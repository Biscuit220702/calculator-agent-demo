#include "calculator/arithmetic.hpp"

namespace calculator {

double multiply(double lhs, double rhs) {
    return lhs * rhs;
}

double divide(double lhs, double rhs) {
    if (rhs == 0.0) {
        throw std::domain_error("division by zero");
    }
    return lhs / rhs;
}

}
