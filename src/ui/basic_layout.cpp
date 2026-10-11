#include "calculator/ui/basic_layout.hpp"

#include <iostream>

namespace calculator {
namespace ui {

void BasicLayout::render(const DisplayState& state) {
    std::cout << "================================\n"
              << "           CALCULATOR\n"
              << "================================\n"
              << "Expression: " << state.expression << '\n'
              << "Result:     " << state.output << '\n'
              << "--------------------------------\n";
}

}
}
