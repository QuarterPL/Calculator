let calculatorLib = null;
WebAssembly.instantiateStreaming(fetch("bundle.wasm"), {}).then((results) => {
  calculatorLib = results.instance.exports;
  console.log(calculatorLib);
});

const button = document.querySelector("button");
button.addEventListener("click", () => {
  console.log(calculatorLib.calculate(5, 43, 3));
});
