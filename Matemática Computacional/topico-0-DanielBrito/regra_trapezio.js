// Console JavaScript Online: https://es6console.com/

// Definição da função:
function f(x) {
  return Math.pow(x, 3) + 12 * Math.pow(x, 2) + 5 * x;
}

// Função que implementa a Regra do Trapézio:
function regraTrapezio(f, a, b) {
  // Calculando primeiro subintervalo:
  resultado = (f(a) + f(b)) / 2.0;

  // Calculando 'h' de acordo com a fórmula:
  h = (b - a) / k;

  // Calculando resultado com base no valor de 'h' e quantidade de subintervalos:
  for (let i = 1; i < k; i++) {
    resultado += f(a + h * i);
  }

  // Retornando resultado final:
  return h * resultado;
}

// Definição do intervalo e quantidade de subintervalos:
let intervalo = [0, 2];
let k = 50;

console.log(regraTrapezio(f, intervalo[0], intervalo[1]));
