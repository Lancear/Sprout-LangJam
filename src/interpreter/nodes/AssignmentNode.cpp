#include <string>
#include <memory>
#include <variant>

#include "AssignmentNode.hpp"
#include "../ErrorHandler.hpp"
#include "../symboltable/SymbolTable.hpp"
#include "../symboltable/Symbol.hpp"

using namespace std;

Symbol AssignmentNode::addSymbols() {
  return children[0]->addSymbols();
}

Symbol AssignmentNode::sematicCheck(Symbol param) {
  Symbol rhs = children[1]->sematicCheck();
  Symbol lhs = children[0]->sematicCheck();
  Symbol sym = lhs;

  if (lhs.isError() || rhs.isError()) {
    return Symbol::ERROR();
  }

  if (lhs.isImmutable()) {
    ErrorHandler::error("lhs is immutable, cannot assign to it");
    sym = Symbol::ERROR();
  }

  if (lhs.dataType.compare(rhs.dataType) != 0) {
    ErrorHandler::error(value + " lhs is not of the same type as rhs");
    sym = Symbol::ERROR();
  }

  return sym;
}

Symbol AssignmentNode::execute(Symbol sym) {
  Symbol rhs = children[1]->execute();
  Symbol lhs = children[0]->execute();

  if(value == "=") lhs.value = rhs.value;
  else if(value == "+=") {
    if(lhs.dataType == "int") lhs.value.emplace<int>(get<int>(lhs.value) + get<int>(rhs.value));
    else lhs.value.emplace<string>(get<string>(lhs.value) + get<string>(rhs.value));
  }
  else if(value == "-=") lhs.value.emplace<int>(get<int>(lhs.value) - get<int>(rhs.value));
  else if(value == "*=") lhs.value.emplace<int>(get<int>(lhs.value) * get<int>(rhs.value));
  else if(value == "/=") {
    if(get<int>(rhs.value) == 0) {
      ErrorHandler::error("x / 0 is undefined");
      return Symbol::ERROR();
    }

    lhs.value.emplace<int>(get<int>(lhs.value) / get<int>(rhs.value));
  }
  else if(value == "%=") {
    if(get<int>(rhs.value) == 0) {
      ErrorHandler::error("x mod 0 is undefined");
      return Symbol::ERROR();
    }

    lhs.value.emplace<int>(get<int>(lhs.value) % get<int>(rhs.value));
  }
  else if(value == "&=") lhs.value.emplace<int>(get<int>(lhs.value) & get<int>(rhs.value));
  else if(value == "|=") lhs.value.emplace<int>(get<int>(lhs.value) | get<int>(rhs.value));
  else if(value == "^=") lhs.value.emplace<int>(get<int>(lhs.value) ^ get<int>(rhs.value));
  else if(value == "<<=") lhs.value.emplace<int>(get<int>(lhs.value) << get<int>(rhs.value));
  else if(value == ">>=") lhs.value.emplace<int>(get<int>(lhs.value) >> get<int>(rhs.value));

  SymbolTable::getInstance()->update(lhs);

  if (lhs.dataType.compare("int") == 0)
    cout << lhs.name << value << ": " << get<int>(SymbolTable::getInstance()->get(lhs.name).value) << endl;
  else 
    cout << lhs.name << value << ": " << get<string>(SymbolTable::getInstance()->get(lhs.name).value) << endl;
  return rhs;
}
