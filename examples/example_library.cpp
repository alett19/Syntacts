#include <Syntacts/Syntacts.hpp>
#include <thread>

using namespace tact;

int main(int argc, char const *argv[])
{
    Session session;
    session.open();

    // create a cue
    auto osc = create<Chirp>(250, 10);
    auto mod = create<Sine>(5);
    auto env = create<ASR>(1,3,1);
    auto cue = create<Cue>(osc, mod, env);

    /// play the cue for reference
    session.play(0, cue);
    std::this_thread::sleep_for(std::chrono::seconds(6));

    // save the cue
    Library::saveCue(cue, "libCue");
    Library::saveCue(cue, "libCue", SaveFormat::JSON);

    // load the cue back in at a later time or in another process
    auto loadedCue = Library::loadCue("libCue");

    // play the cue for reference (should be exactly same as before)
    session.play(0, loadedCue);
    std::this_thread::sleep_for(std::chrono::seconds(6));

    // export cue as different formats
    Library::exportCue(cue, "libCue.wav",  ExportFormat::WAV);
    Library::exportCue(cue, "libCue.aiff", ExportFormat::AIFF);
    Library::exportCue(cue, "libCue.csv",  ExportFormat::CSV);

    printf("All Good!");
    return 0;
}
