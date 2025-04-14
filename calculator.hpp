#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>

// this function should expect that `expression` has already been
// validated and thus throw no exceptions
double parse_number(const std::string &expression);
bool is_valid_conversion(const std::string the_string);  // function for determining if the string is valid for conversion


#endif // __CALCULATOR_HPP
