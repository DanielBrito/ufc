#include <functional>
#include <iostream>

// double -> double
using Fn1 = std::function<double(double)>;
// double -> double -> double
using Fn2 = std::function<double(double, double)>;
// Fn1 -> double -> double -> double
using Quad = std::function<double(Fn1, double, double)>;

double newtonCottes1(Fn1 f, double a, double b){
  return (b - a)*((f(a) + f(b)) / 2);
}

double applyQuadOnSubintervals(Quad quad, Fn1 f, double a, double b, unsigned int n){
  double h      = (b - a) / n;
  double result = 0.0;

  for (unsigned int i = 0; i < n; i++){
    double xi = a + i*h;

    result += quad(f, xi, xi + h);
  }

  return result;
}

double doubleIntegral(Fn2 f, double a, double b, Fn1 c, Fn1 d, Quad innerQd, Quad outerQd){
  auto F = [f, innerQd, c, d](double x){
             auto g = [f, x](double y){
                        return f(x, y);
                      };
             return innerQd(g, c(x), d(x));
           };
  return outerQd(F, a, b);
}

double func(double x){
  return 2*x + 3;
}

double func2(double x, double y){
  return x*y + 3*x + 4*y + 5;
}

double c(double x){
  return 4*x;
}

double d(double x){
  return 5*x;
}

int main(){
  double res1 = applyQuadOnSubintervals(newtonCottes1, func, 0.0, 3.0, 5);
  double res2 = doubleIntegral(func2, 0.0, 3.0, c, d, newtonCottes1, newtonCottes1);

  std::cout << res1 << std::endl;
  std::cout << res2 << std::endl;

  return 0;
}
