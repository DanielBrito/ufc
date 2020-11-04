// Console JavaScript Online: https://es6console.com/

// Definição da função:
function f(x) {
  return 3 * Math.pow(x, 2) - x;
}

// Função para calcular o tamanho dos intervalos:
function h(a, b) {
  return (b - a) / 2;
}

// Aplicando a Regra de Simpson 1/3 simples:
function regraSimpsonSimples1_3(f, a, b) {
  return (h(a, b) / 3) * (f(a) + 4 * f((a + b) / 2) + f(b));
}

// Aplicando a Regra de Simpson 3/8 simples:
function regraSimpsonSimples3_8(f, a, b) {
  return (3 / 8) * h(a, b) * (f(a) + (3 * ((2 * a + b) / 3)) + (3 * (2 * b + a) / 3) + f(b));
}

// Aplicando a Regra de Simpson 1/3 composta:
function regraSimpsonComposta1_3(f, a, b) {
  let resultado = f(a) + f(b);
  let h = (b - a) / k;

  for(let i=1; i<k; i+=2){
  	resultado += 4 * f(a + i * h);
  }

  for(let i=2; i<k-1; i+=2){
  	resultado += 2 * f(a + i * h);
  }

  return (h/3) * resultado;
}

// Aplicando a Regra de Simpson 3/8 composta:
function regraSimpsonComposta3_8(f, a, b) {
  let resultado = f(a) + f(b);
  let h = (b - a) / k;

  for(let i=1; i<k; i++){
  	if(i%3 == 0){
  		resultado += 2 * f(a + i * h);
  	}
  	else{
  		resultado += 3 * f(a + i * h);
  	}
  }

  return ((3*h)/8) * resultado;
}

// Definição do intervalo e quantidade de subintervalos:
let intervalo = [0, 2];
let k = 30;

console.log("Regra de Simson simples:");
console.log(regraSimpsonSimples1_3(f, intervalo[0], intervalo[1]));
console.log(regraSimpsonSimples3_8(f, intervalo[0], intervalo[1]));

console.log("Regra de Simpson composta:");
console.log(regraSimpsonComposta1_3(f, intervalo[0], intervalo[1]));
console.log(regraSimpsonComposta3_8(f, intervalo[0], intervalo[1]));
