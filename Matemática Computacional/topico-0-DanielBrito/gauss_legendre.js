// Console JavaScript Online: https://es6console.com/

// Definição da função:
function f(n) {
  return Math.pow(n, 4) + 2 * n + 1;
}

// Definindo valores para xi, wi:
let ordem2 = [
  [Math.sqrt(3) / 3, 1],
  [-Math.sqrt(3) / 3, 1],
];

let ordem3 = [
  [0, 8 / 9],
  [Math.sqrt(15) / 5, 5 / 9],
  [-Math.sqrt(15) / 5, 5 / 9],
];

let ordem4 = [
  [-Math.sqrt(3 / 7 - (2 / 7) * Math.sqrt(6 / 5)), (18 + Math.sqrt(30)) / 36],
  [Math.sqrt(3 / 7 - (2 / 7) * Math.sqrt(6 / 5)), (18 + Math.sqrt(30)) / 36],
  [-Math.sqrt(3 / 7 + (2 / 7) * Math.sqrt(6 / 5)), (18 - Math.sqrt(30)) / 36],
  [Math.sqrt(3 / 7 + (2 / 7) * Math.sqrt(6 / 5)), (18 - Math.sqrt(30)) / 36],
];

// Implementação da Quadratura de Gauss-Legendre:
function gaussLegendre(f, a, b, n) {

  let xi, wi, resultado = 0;

	// Aplicando quadratura:
  for (let i = 0; i < n; i++) {
    if (n === 2) {
      xi = ordem2[i][0];
      wi = ordem2[i][1];
    } else if (n === 3) {
      xi = ordem3[i][0];
      wi = ordem3[i][1];
    } else if (n === 4) {
      xi = ordem4[i][0];
      wi = ordem4[i][1];
    }

		// Atualizando resultado parcial:
    resultado += wi * f(((b - a) / 2) * xi + (a + b) / 2);
  }

	// Retornando resultado da aproximação:
  return resultado * ((b - a) / 2);
}

let intervalo = [-1, 1];
let n = 3;

console.log(gaussLegendre(f, intervalo[0], intervalo[1], n));
