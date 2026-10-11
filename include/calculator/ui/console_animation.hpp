#pragma once

#include "calculator/ui.hpp"

namespace calculator {
namespace ui {

class ConsoleAnimation final : public Animation {
public:
    void play(AnimationEvent event) override;
};

}
}
