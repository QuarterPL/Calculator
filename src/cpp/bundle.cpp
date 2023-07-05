#include <emscripten/bind.h>
#include "calc/Calculator.h"

using namespace emscripten;
class Calculator;

EMSCRIPTEN_BINDINGS(module)
{
    class_<Calculator>("Calculator")
        .constructor<>()
        .function("calculate", &Calculator::calculate);
}