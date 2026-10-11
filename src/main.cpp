#include "calculator/arithmetic.hpp"
#include "calculator/ui/basic_layout.hpp"
#include "calculator/ui/console_animation.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

int main() {
    calculator::ui::BasicLayout layout;
    calculator::ui::ConsoleAnimation animation;
    layout.render({"", "Enter: number operator number (example: 2 + 3); q to quit"});

    std::string line;
    while (true) {
        std::cout << "calc> " << std::flush;
        if (!std::getline(std::cin, line) || line == "q" || line == "quit") {
            break;
        }
        if (line.empty()) {
            continue;
        }

        animation.play(calculator::ui::AnimationEvent::input_changed);
        try {
            std::istringstream expression(line);
            double lhs;
            double rhs;
            char operation;
            if (!(expression >> lhs >> operation >> rhs)) {
                throw std::invalid_argument("enter an expression like 2 + 3");
            }
            expression >> std::ws;
            if (!expression.eof()) {
                throw std::invalid_argument("unexpected input after the expression");
            }

            double result;
            switch (operation) {
            case '+': result = calculator::add(lhs, rhs); break;
            case '-': result = calculator::subtract(lhs, rhs); break;
            case '*': result = calculator::multiply(lhs, rhs); break;
            case '/': result = calculator::divide(lhs, rhs); break;
            default: throw std::invalid_argument("operator must be +, -, *, or /");
            }

            std::ostringstream output;
            output << result;
            animation.play(calculator::ui::AnimationEvent::calculation_completed);
            layout.render({line, output.str()});
        } catch (const std::exception& error) {
            animation.play(calculator::ui::AnimationEvent::calculation_failed);
            layout.render({line, std::string("Error: ") + error.what()});
        }
    }

    std::cout << "Goodbye.\n";
    return 0;
}
