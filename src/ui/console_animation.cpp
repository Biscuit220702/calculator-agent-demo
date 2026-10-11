#include "calculator/ui/console_animation.hpp"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <thread>

namespace calculator {
namespace ui {

void ConsoleAnimation::play(AnimationEvent event) {
    const char* message;
    switch (event) {
    case AnimationEvent::input_changed:
        message = "Input updated";
        break;
    case AnimationEvent::calculation_completed:
        message = "Calculation complete";
        break;
    case AnimationEvent::calculation_failed:
        message = "Calculation failed";
        break;
    default:
        throw std::invalid_argument("unknown animation event");
    }

    constexpr char frames[] = {'|', '/', '-', '\\'};
    for (char frame : frames) {
        std::cout << '\r' << message << ' ' << frame << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    std::cout << '\r' << message << "   \n";
}

}
}
