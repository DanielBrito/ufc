// Console JavaScript Online: https://es6console.com/

// Definição da função contínua:
function f(n) {
  return Math.pow(n, 3) - 9 * n + 3;
}

// Derivada de f(n) hardcoded:
function derivada(n) {
  return 3 * Math.pow(n, 2) - 9;
}

// Calculando de acordo com a fórmula: x(k+1) = x(k) - f(k) / f'(k)
function calcularProximoPonto(ponto) {
  return ponto - f(ponto) / derivada(ponto);
}

// Função que implementa o Método de Newton:
function metodoNewton(pontoAtual) {
  // Recalcular enquanto o resultado for maior que 'epsilon':
  while (Math.abs(f(pontoAtual)) >= epsilon) {
    // Exibição do ponto corrente:
    console.log(pontoAtual);

    // Calculando próximo ponto:
    var proximoPonto = calcularProximoPonto(pontoAtual);

    // Atualizando ponto atual:
    pontoAtual = proximoPonto;
  }

  return pontoAtual;
}

// Definição do ponto inicial:
var pontoAtual = 1.5;

// Definição da precisão do resultado:
var epsilon = 0.01;

console.log(metodoNewton(pontoAtual));
