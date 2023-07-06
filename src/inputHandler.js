import { calculatorLib } from "./bundle";

const resultButton = document.getElementById("get-result-button");
const resultOutput = document.getElementById("result-output");
resultButton.addEventListener("click", () => {
  const a = +document.getElementById("a").value;
  const b = +document.getElementById("b").value;
  const sign = document.getElementById("sign").value.charCodeAt(0);
  resultOutput.textContent = `=> ${calculatorLib.calculate(a, sign, b)}`;
});
