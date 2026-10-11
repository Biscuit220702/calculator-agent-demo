#pragma once

#include <stdexcept>

namespace calculator {

double add(double lhs, double rhs);
double subtract(double lhs, double rhs);
double multiply(double lhs, double rhs);
// Throws std::domain_error when rhs is zero.
double divide(double lhs, double rhs);

}
