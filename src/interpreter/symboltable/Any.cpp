#include <string>

#include "Any.hpp"

using namespace std;

AnyType AnyType::operator=(AnyAny * any) {
  _any = any;
  return *this;
}

string AnyType::type() {
  return string( _any->type().name() );
}
