module Trabalho where

-- 1

newton :: Fractional a => (a -> a) -> a -> [a]
newton f x0 = iterate aux x0 where
              aux x = x - (f x / diff f x)
              diff f x = (f (x + h) - f x) / h
              h = 0.001

-- 2.1

-- Tem de especificar o tipo para o compilador saber armazenar os resultados intermediarios e tornar a implementacao mais eficiente. Eu especifiquei como Double pq eu vou fazer divisoes mais na frente.
fibs :: [Double]
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

-- Compara com essa
fibsSlow :: Fractional a => [a]
fibsSlow = 0 : 1 : zipWith (+) fibsSlow (tail fibsSlow)

-- 2.2
primes :: [Int] -- Se eu vou reusar os resultados já calculados, eu especifico o tipo.
primes = aux $ 2 : (iterate (+2) 3) where
         possibleDivisors x = takeWhile (<= (x `div` 2)) primes
         isPrime x = and $ map ((/= 0) . mod x) (possibleDivisors x)
         aux (x:xs) = x : filter isPrime xs
         
-- 2.3
goldenRatio :: [Double]
goldenRatio = zipWith (/) (tail fibs) fibs
