#pragma once

#include "calculator/ui.hpp"

namespace calculator {
namespace ui {

class BasicLayout final : public Layout {
public:
    void render(const DisplayState& state) override;
};

}
}
