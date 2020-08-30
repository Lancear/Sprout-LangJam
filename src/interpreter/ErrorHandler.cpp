#include <string>
#include <iostream>

#include "ErrorHandler.hpp"

using namespace std;

bool ErrorHandler::hadError = false;

/**
 * logs the error and remembers that there was an error. 
 * if there were errors, after the semantic checks the interpreter will stop.
 */
void ErrorHandler::error(string errMessage) {
  ErrorHandler::hadError = true;
  cout << errMessage << endl;
}
