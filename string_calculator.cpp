#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout; 
using std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    unsigned int dig = 0;
    dig = digit - '0';
    bool is_real = false;
      for (unsigned int i = 0; i < 10; ++i) {
        if (dig == i) {
          is_real = true;
        }
      }
      if (is_real == false) {
        throw std::invalid_argument("entered incorrect range");
      }
    return dig;
}

char decimal_to_digit(unsigned int decimal) {
    char digit = decimal + 48;
    bool is_real = false; 
      for (unsigned int j = 0; j < 10; ++j) {
        if (decimal == j) {
          is_real = true;
        }
      }
      if (is_real == false) {
        throw std::invalid_argument("calculated incorrectly");
      }
    return digit;
}

string trim_leading_zeros(string num) {
  bool is_neg = false;
  if (num.at(0) == '-') {
      num = num.substr(1);
      is_neg = true;
    }
  else {
    is_neg = false;
  }

  if (num.at(0) == '0') {
    while (num.at(0) == '0') {
      if (num.substr(1) != "") {
        num = num.substr(1);
      }
      else {
        is_neg = false;
        break;
      }
    }
  }
  
  else {
      num = num;
  }

  if (is_neg == true && num != "0") {
    num = '-' + num;
  }
  
  return num;
}

string add(string lhs, string rhs) {
//checking negative
  bool is_neg = false;

  if ((lhs[0] == '-') && rhs[0] == '-') {
    lhs = lhs.substr(1);
    rhs = rhs.substr(1);
    is_neg = true;
    //std::cout << lhs << " and " << rhs << " were negative" << std::endl;
  }
  else if (((lhs.at(0) == '-') && !(rhs.at(0) == '-')) || (!(lhs.at(0) == '-') && (rhs.at(0) == '-'))) {
    throw std::invalid_argument("entered unlike integers");
  }
  else {
    is_neg = false;
  }
//initialize variables 
  std::string final_str;
  int length1 = lhs.length();
  int length2 = rhs.length();
  int final_len = length1 + 1;

//set sum length
  if (length2 > final_len) {
    final_len = length2+2;
  }

  for (int i = 0; i < final_len; ++i) {
    final_str += "0";
  }

//resize strings
  for (int j = 0; j < (final_len - length1); ++j) {
    lhs = '0' + lhs;
  }

  for (int k = 0; k < (final_len - length2); ++k) {
    rhs = '0' + rhs;
  }

  //std::cout << num1 << std::endl; //debug
  //std::cout << num2 << std::endl; //debug
  //std::cout << final_str << std::endl; //debug

// initialize loop variables
  int sum;
  std::string teststr = final_str;
  int add1;
  int add2;
  int carry;

// loop for sum
  for (int n = final_len; n > -1; --n) {
    add1 = lhs[n] - '0';
    add2 = rhs[n] - '0';
    carry = teststr[n] - '0';
    //std::cout << add1 << " + " << add2 << " carry over: " << carry <<std::endl;
    sum = add1 + add2 + carry;
    

    char digit;

// no carry over
    if (sum < 10) {
      digit = sum + 48;
    }

//carry over
    else {
      digit = (sum % 10) + 48;
      int carry_over = (sum / 10);
      char prev_digit = (carry_over + 48);
      teststr[n - 1] = prev_digit;
    }

    final_str[n] = digit;
  }
//negative check
    std::string negative = "-";

    if (is_neg != true) {
      negative = "";
    }

//trim zeros and reinsert negative
    final_str = trim_leading_zeros(final_str);
    final_str = negative + final_str;

  return final_str;
}

std::string multiply(std::string lhs, std::string rhs) {
//checking negative
  bool is_neg = false;
  if (lhs[0] == '-' && rhs[0] == '-') {
    rhs = rhs.substr(1);
    lhs = lhs.substr(1);
    is_neg = false;
  }
  else if (lhs[0] == '-') {
    lhs = lhs.substr(1);
    is_neg = true;
  }
  else if (rhs[0] == '-') {
    rhs = rhs.substr(1);
    is_neg = true;
  }
  else {
    is_neg = false;
  }

//initialize variables 
  std::string final_str;

  if (lhs < rhs) {
    std::string placeholder = rhs;
    rhs = lhs;
    lhs = placeholder;
  }

  int length1 = lhs.length();
  int length2 = rhs.length();
  int final_len = length1 + length2;

  for (int i = 0; i < final_len; ++i) {
    final_str += "0";
  }



//resize strings
  for (int j = 0; j < (final_len - length1); ++j) {
    lhs = '0' + lhs;
  }

  for (int k = 0; k < (final_len - length2); ++k) {
    rhs = '0' + rhs;
  }

// initialize loop variables

  std::string digit_product = "0";

  int num1 = 0;
  int num2 = 0;
  int prod_num = 0;
  int prev_num = 0;
  char prod_char = '0';
  bool carry_over = false;
  std::string carry = final_str.substr(0);
  std::string reset = final_str.substr(0);


// loop for product

//loop through left hand side
  for (int i = 0; i < final_len; ++i) {
    digit_product = "";
    num1 = lhs[i] - '0';
//loop through right hand side
    for (int j = 0; j < final_len; ++j) { 
      num2 = rhs[j] - '0';
      prod_num = num1 * num2; 
//set product
//case without carry over
      if (prod_num < 10) { 
        prod_char = prod_num + 48; 
      }

//carry over
      else {
        prev_num = (prod_num / 10); 
        prod_num = prod_num % 10;
        prod_char = prod_num + 48;
        carry_over = true;
      }

//add final product to iterating string
      if (carry_over == true) {
        char prev_char = prev_num + 48;
        carry[j - 1] = prev_char;
        carry_over = false;
      }

      prev_num = 0;
      digit_product = digit_product + prod_char;

    }
//add string to final string and reset
    digit_product = add(carry, digit_product);
    for (int h = i; h < final_len - 1; ++h) {
      digit_product += "0";
    }
    final_str = add(final_str, digit_product);
    digit_product = "0";
    carry = reset;
  }

//negative check
    std::string negative = "-";

    if (is_neg != true) {
      negative = "";
    }

//trim zeros and reinsert negative
    final_str = trim_leading_zeros(final_str);
    final_str = negative + final_str;

  return final_str;
}
