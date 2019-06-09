#pragma once

#include <Syntacts/Config.hpp>
#include <Syntacts/Generator.hpp>

namespace syntacts
{

/// Abstract base class for object which produces a periodic, oscillating signal
class SYNTACTS_API Oscillator : public Generator {
public:

    /// Constructs an Oscillator with specified frequency
    Oscillator(float frequency = 1.0f);

    /// Sets the oscillator frequency in Hz
    void setFrequency(float frequency);

protected:

    float m_frequency;  ///< oscillator frequency

};


/// A sine wave Oscillator
class SYNTACTS_API SineWave : public Oscillator {
public:

    // Inherited Constructor
    using Oscillator::Oscillator;

protected:

    /// Implements sine wave oscillation
    virtual float onSample(float t) override;

};


/// A square wave Oscillator
class SYNTACTS_API SquareWave : public Oscillator {
public:

    // Inherited Constructor
    using Oscillator::Oscillator;

protected:

    /// Implements square wave oscillation
    virtual float onSample(float t) override;

};


/// A saw wave Oscillator
class SYNTACTS_API SawWave : public Oscillator {
public:

    // Inherited Constructor
    using Oscillator::Oscillator;

protected:

    /// Implements saw wave oscillation
    virtual float onSample(float t) override;

};

/// A triangle wave Oscillator
class SYNTACTS_API TriWave : public Oscillator {
public:

    // Inherited Constructor
    using Oscillator::Oscillator;

protected:

    /// Implements saw wave oscillation
    virtual float onSample(float t) override;

};

class SYNTACTS_API SineWaveFM : public Oscillator {
public:

    /// Constructs a frequency modulated sinewave
    SineWaveFM(float frequency, float modulation, float index);

protected:

    virtual float onSample(float t) override;

private:

    float m_modulation;
    float m_index;

};

} // namespace syntacts