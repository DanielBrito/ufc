 module Aula4_Laboratório1 where

-- Vamos escrever as seguintes funcoes usando recursao por cauda:

myLength :: [a] -> Int
myLength xs = f xs 0 where
              f [] acc = acc
              f (x:xs) acc = f xs (acc + 1)


myConcat :: [[a]] -> [a]
myConcat xss = f xss [] where
		       f [] acc = acc
		       f (x:xs) acc = f xs (myCc acc x)
	
myCc :: [a] -> [a] -> [a]
myCc [] ys = ys
myCc (x:xs) ys = x : myCc xs ys
	       

myReverse :: [a] -> [a]
myReverse xs = f xs [] where
	           f [] ys = ys
	           f (x:xs) ys = f xs (x:ys)

-- Agora, escreva funcoes que, dada uma lista de inteiros, retornam seu somatorio e produtorio, respectivamente:

mySum :: [Int] -> Int
mySum [] = 0
mySum (x:xs) = x + mySum xs


myProd :: [Int] -> Int
myProd [] = 1
myProd (x:xs) = x * myProd xs


-- E uma funcao que, dada uma lista de inteiros, retorna a lista com o quadrado desses inteiros:

squares :: Num a => [a] -> [a]
squares [] = []
squares (x:xs) = x*x : squares xs

squaresV2 :: [Int] -> [Int]
squaresV2 xs = f xs [] where
			 f [] acc = acc
			 f (x:xs) acc = f xs (myCc acc [x*x])
