#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
  std::cout << "String Calculator" << std::endl;
  std::cout << "\"q\" or \"quit\" or ctrl+d to exit" << std::endl;


// initialize variables
  std::string first_string;
  std::string second_string;
  std::string ans;

  char op = '0';
  bool adding = false;
  bool multiplying = false;
  cout << ">> ";
  std::cin >> first_string;
  std::cin >> op;
  std::cin >> second_string;
  //cout << endl;

  while (first_string != "q" && first_string != "quit") {

// trim zeroes
    first_string = trim_leading_zeros(first_string);
    second_string = trim_leading_zeros(second_string);

// check operation
    switch (op) {
      case '*':
        multiplying = true;
        break;
      case '+':
        adding = true;
        break;
      default:
        throw std::invalid_argument("the operator entered must be + or *.");
    }

// adding
    if (adding == true) {
      cout << "ans =" << endl;
      //cout << endl;
      cout << endl;
      ans = add(first_string, second_string);
      std::cout << "    " << ans << std::endl;
      cout << endl;
    }

// multiplying
    if (multiplying == true) {
      cout << "ans =" << endl;
      //cout << endl;
      cout << endl;
      ans = multiply(first_string, second_string);
      std::cout << "    " << ans << std::endl;
      cout << endl;
    }

// reset for next loop
    op = '0';
    adding = false;
    multiplying = false;
    cout << ">> ";
    std::cin >> first_string;
    std::cin >> op;
    std::cin >> second_string;
    //cout << endl;
    
    ans = "";


// end



  }
  std::cout << "farvel!" << std::endl;
  cout << endl;
}

