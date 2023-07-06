(() => {
  let e = null;
  WebAssembly.instantiateStreaming(fetch("bundle.wasm"), {}).then((t) => {
    (e = t.instance.exports), console.log(e);
  }),
    document.querySelector("button").addEventListener("click", () => {
      console.log(e.calculate(5, 43, 3));
    });
})();
