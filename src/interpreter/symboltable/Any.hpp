#pragma once

#include <typeinfo>
#include <string>

using namespace std;

class AnyAny {
  public:
    virtual const type_info& type() = 0;
};

template<typename DataType>
class Any : public AnyAny {
  public:
    explicit Any(const DataType& value) {
      _value = value;
    }

    const type_info& type() {
      return typeid(DataType);
    }

    DataType value() {
      return _value;
    }

  protected:
    DataType _value;
};

class AnyType {
  public:
    AnyType operator=(AnyAny * any);
    string type();

    template <typename T>
    T value() {
      return static_cast<Any<T>*>(_any)->value();
    }

    template <typename T>
    bool isOfType() {
      return _any != NULL && _any->type().hash_code() == typeid(T).hash_code();
    }

  protected:
    AnyAny * _any = NULL;
};
