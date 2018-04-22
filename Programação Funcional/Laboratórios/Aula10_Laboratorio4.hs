module Aula10_Laboratorio4 where

-- Escreva o mergesort. Vc vai precisar escrever as subfuncoes merge e split. Split deve percorrer a lista somente uma vez.

mySplit :: Int -> [a] -> ([a], [a])
mySplit _ [] = ([], [])
mySplit 1 (x:xs) = ([x], xs)
mySplit m (x:xs) = (x:ys, yss) where
                   (ys, yss) = mySplit (m-1) xs

merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) 
      | (x <= y)  = x:(merge xs (y:ys)) 
      | otherwise = y:(merge (x:xs) ys)

mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort a) (mergesort b) where
               (a, b) = mySplit (div (length xs) 2) xs

-- Hora de criar alguns programas!

-- IO também é uma mônada. Ela indica que o resultado foi obtido iteragindo com o sistema operacional.

main :: IO ()
main = program1

-- Apenas um hello world

program1 :: IO ()
program1 = putStrLn "Hello, World!"

-- Uma interação com o usuário.

program2 :: IO ()
program2 = getLine >>= putStrLn

-- Agora um novo operador monádico

program3 :: IO ()
program3 = putStrLn "Digite algo" >> getLine >>= putStrLn

-- Vimos alguns exemplos de interações com o sistema operacional.
-- Como vamos utilizar o tipo de funções que desenvolvemos até agora no meio dessas interações

program4 :: IO ()
program4 = getInput >>= pure . doSomething >>= setOutput where
           getInput = getLine >>= getMoreInput -- Tem como ser mais sucinto do que criar uma função apenas para tomar outra string, mas vamos deixar para depois.
           getMoreInput str = getLine >>= pure . ((,) str)
           doSomething (str1, str2) = x + y where
                                      x = read str1 :: Int
                                      y = read str2 :: Int
           setOutput = putStrLn . show

-- Já que vc implementou mergesort, escreva um programa que lê uma linha de entrada do usuário e retorna a linha ordenada.

program5 :: IO ()
program5 = getInput >>= setOutput where
                        getInput = getLine >>= pure . mergesort
                        setOutput = putStrLn . show
