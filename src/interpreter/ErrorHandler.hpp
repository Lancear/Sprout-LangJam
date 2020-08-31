#pragma once

#include <string>
#include <iostream>

using namespace std;

class ErrorHandler {
  public:
    static bool hadError;
	static void error(string errorMessage, int line, int col);
};
