module Trabalho1 where

-- QUESTÃO 1


-- QUESTÃO 2.1

fibonaccis :: [Integer]
fibonaccis = 0 : 1 : zipWith (+) fibonaccis (tail fibonaccis)

-- QUESTÃO 2.2

primos :: [Integer]
primos = filtro (2 : [3, 5..]) where 
         filtro (p:xs) = p : filtro [x | x <- xs, x `mod` p > 0]

-- QUESTÃO 2.3

fibonaccis' :: [Double]
fibonaccis' = 1 : 2 : zipWith (+) fibonaccis' (tail fibonaccis')

fibonaccis'' :: [Double]
fibonaccis'' = 2 : 3: zipWith (+) fibonaccis'' (tail fibonaccis'')

proporcao :: [Double] -> [Double] -> [Double] -- Parametros fibonaccis' fibonaccis''
proporcao (x:xs) (y:ys) = (y/x) : proporcao xs ys