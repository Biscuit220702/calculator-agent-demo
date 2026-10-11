#pragma once

#include <string>

namespace calculator {
namespace ui {

struct DisplayState {
    // Both fields are display-ready text; output may contain an error message.
    std::string expression;
    std::string output;
};

class Layout {
public:
    virtual ~Layout() = default;
    virtual void render(const DisplayState& state) = 0;
};

enum class AnimationEvent {
    input_changed,
    calculation_completed,
    calculation_failed
};

class Animation {
public:
    virtual ~Animation() = default;
    virtual void play(AnimationEvent event) = 0;
};

}
}
