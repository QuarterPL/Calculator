export let calculatorLib = null;
WebAssembly.instantiateStreaming(fetch("bundle.wasm"), {}).then((results) => {
  calculatorLib = results.instance.exports;
  console.log(calculatorLib);
});
