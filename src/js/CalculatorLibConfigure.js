const ffi = require("ffi-napi");

const CalculatorLib = new ffi.Library("./../CalculatorLib/Calculator", {
  calculate: ["double", ["double", "char", "double"]],
});

console.log(CalculatorLib.calculate(5, "+", 10));
