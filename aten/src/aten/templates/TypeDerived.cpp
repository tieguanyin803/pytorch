#include "TensorLib/${Type}.h"
#include "TensorLib/${Storage}.h"
#include "TensorLib/${Tensor}.h"
#include "TensorLib/${Processor}Generator.h"
#include "TensorLib/Utils.h"
#include <iostream>

template<typename Derived, typename Base>
static inline Derived* checked_cast(Base* b) {
  return dynamic_cast<Derived*>(b);
}

namespace tlib {

${Type}::${Type}(Context* context)
: context(context) {}
ScalarType ${Type}::scalarType() {
  return ScalarType::${ScalarName};
}
Processor ${Type}::processor() {
  return Processor::${Processor};
}
bool ${Type}::isSparse() { return false; }
bool ${Type}::isDistributed() { return false; }

Storage * ${Type}::newStorage() {
  return new ${Storage}(context);
}
Storage * ${Type}::newStorage(size_t size) {
  return new ${Storage}(context,size);
}
Generator * ${Type}::newGenerator() {
  return new ${Processor}Generator(context);
}

const char * ${Type}::toString() const {
  return "${Type}";
}

const char * ${Type}::typeString() {
  return "${Type}";
}

// example
Tensor * ${Type}::add(Tensor & a, Tensor & b) {
  std::cout << "add ${Tensor}\n";
  return &a;
}

${type_derived_method_definitions}

}