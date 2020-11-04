// Console JavaScript Online: https://es6console.com/

// Definição da função contínua:
function f(n) {
  return Math.pow(n, 3) - 9 * n + 5;
}

// Modularizando cálculo da raiz:
function calculaX(f, a, b) {
  return a + (f(a) * (a - b)) / (f(b) - f(a));
}

// Função que implementa o método da posição falsa:
function posicaoFalsa(f, a, b) {

	// Verificando precisão em relação à 'epsilon':
	if (Math.abs(f(b)) <= epsilon){
		return b;
	}
	else
	if(Math.abs(f(a)) <= epsilon){
		return a;
	}

  // Repetindo o procedimento baseado no número de iterações pré-definido:
  for (let i = 0; i < iteracoes; i++) {

  	// Imprimindo extremos do intervalo corrente:
    console.log(`[${a}, ${b}]`);

    // Calculando novo valor de 'x':
    let x = calculaX(f, a, b);

    // Verificando precisão em relação à 'epsilon':
    if (Math.abs(f(x)) <= epsilon) {
      return x;
    }

    // Atualizando intervalo:
    (f(a)*f(x) > 0) ? a = x : b = x;

	  // Verificando precisão em relação à 'epsilon':
	  if (Math.abs(b - a) <= epsilon) {
	    return a;
	  }
  }

  return x;
}

// Definindo as restrições para o problema:
let iteracoes = 2;
let epsilon = 0.01;

// Definindo valores do intervalo:
let a = 0.5;
let b = 1.0;

console.log(posicaoFalsa(f, a, b));
