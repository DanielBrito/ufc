// Console JavaScript Online: https://es6console.com/

// Definição da função unária:
function f(x){
	return Math.sin(x);
}

// Forward difference (página 26):
function derivada_(f, a, h){
	return (f(a+h)-f(a))/h;
}

// Central difference (página 27):
function derivada__(f, a, h){
	return (f(a+h)-f(a-h))/(2*h);
}

// Central difference (página 29):
function derivada___(f, a, h){
	return (-f(a+2*h)+8*f(a+h)-8*f(a-h)+f(a-2*h))/(12*h);
}

let a = 0;
let h1 = 0.01;
let h2 = 0.001;
let h3 = 0.0001;

console.log(derivada_(f, a, h1))   // 0.9999833334166665
console.log(derivada__(f, a, h2))  // 0.9999998333333416
console.log(derivada___(f, a, h3)) // 1