#include "calculator.hpp"
#include <cstring>
#include <cmath>

bool is_valid_conversion(const std::string the_string){
  bool has_decimal = false;
  char valid_nums[11] = "0123456789";
  for (int index = 0; index < size(the_string); index++){
    if (the_string[index] == '.'){
      if (not has_decimal){
        has_decimal = true; // if the val is the first decimal change the variable
      }else{
        return false; // if this is the second decimal in the string
      }
    } else if (the_string[index] == '+' or the_string[index] == '-'){  // no issues if value is + or -
      if (index != 0){
        return false; // if theres a + or - anywhere other than the first char, then it's in the middle of the string
    }} else{
      bool is_num = false;
      for(int index_2 = 0; index_2 < 10; index_2++){ // now to test if the value is a number
        if (valid_nums[index_2] == the_string[index]){
          is_num = true;
        }
      }
      if (not is_num){  // if the value isn't a decimal, +, -, or num
        return false;
      }}
    }
  return true; // if the function finds no wrong elements
}

int ipow(int base, int exp)  // quick int based exponent function ripped from stack overflow
{
  int result = 1;
  for (;;)
  {
    if (exp & 1)
      result *= base;
    exp >>= 1;
    if (!exp)
      break;
    base *= base;
  }

  return result;
}

double parse_number(const std::string &expression){
  // split by "." prune +/-, and have two ints that you add with the other stuff
  		double output;
        std::string upper = expression.substr(0, expression.find(".")); // returns the '+whole nums'
        std::string lower = expression.substr(expression.find(".")+1);
        bool negative = false;
        if (upper[0] == '-'){
          negative = true;
          upper.erase(0, 1); // if theres a prefix, identifies it and removes it to allow conversion to int
        } else if (upper[0] == '+'){
          upper.erase(0, 1);  // no need to change negative value if the num is pos
        }
        int int_upper = std::stoi(upper);  // lab never said anything about ints, only floats
        int int_lower = std::stoi(lower);
        if (negative){
          int_upper = int_upper + 123;
          int_lower = int_lower + 456;
          if (size(std::to_string(int_lower)) > size(lower)){  // if a carry over is necessary
            int_upper += 1;
            int_lower = int_lower - ipow(10,size(std::to_string(int_lower)));  // remove the largest digit
          }
        }else{  // num is pos
          int_upper = int_upper - 123;
          int_lower = int_lower - 456;
          if(int_lower < 0){  // carry over stuff
            int_upper -= 1;
            int_lower = int_lower + (ipow(10,size(std::to_string(int_lower))));
          }
        }
        // now the seperate sums are evaluated, now to move on to puting them back together in a organized way
        double fl_upper = static_cast<double>(int_upper);  // converts int to float
        double fl_lower = static_cast<double>(int_lower) /ipow(10,lower.size());  // int to float,
        // but now in a decimal form
        if (fl_upper < 0){
          if (fl_lower < 0){
            output = fl_upper + fl_lower;  // if both neg
          }else{
            output = fl_upper - fl_lower;
          }
        }else{
          if (fl_lower > 0){
            output = fl_upper + fl_lower;  // if both pos
          }else{
            output = fl_upper - fl_lower;
          }
        }
        return output;
}

