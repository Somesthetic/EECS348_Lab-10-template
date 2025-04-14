#include "calculator.hpp"

bool is_valid_conversion(const std::string the_string){
  bool has_decimal = false;
  for (int index = 0; index < size(the_string); index++){
    if (the_string[index] == '.'){
      has_decimal = true;  // if the val is a decimal change the variable
    } else if (the_string[index] == '+' or the_string[index] == '-'){
    }  // no issues if value is + or -

  }
}