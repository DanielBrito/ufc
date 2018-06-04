module Aula11 where

-- Escreva a funcao enumerate.

enumerate :: [a] -> [(Int, a)]
enumerate [] = []
enumerate (x:xs) = zip [1..] (x:xs)

-- Escreva uma função que determina se uma lista e um palindromo.

palindrome :: Eq a => [a] -> Bool
palindrome [] = True
palindrome [x] = True
palindrome (x:xs) = myIf(x==(myLast xs)) (palindrome (myInit xs)) False

-- Escreva uma função que elimina elementos duplicados consecutivos de uma lista
-- Ex: removeDuplicates [1,2,2,3,3,3,4,5,5] == [1,2,3,4,5]

removeDuplicates :: Eq a => [a] -> [a]
removeDuplicates [] = []
removeDuplicates [x] = [x]
removeDuplicates (x:xs) = x : removeDuplicates (dropWhile (==x) xs)

main :: IO ()
main =  readFile "texto0.txt" >>=
        pure . words >>=
        print

program1 :: IO ()
program1 =  readFile "texto1.txt" >>=
            pure . removeDuplicates . words >>=
            print

-- Escreva um programa que determina se o conteudo de texto.txt e um palindromo.

program2 :: IO ()
program2 =  readFile "texto2.txt" >>=
            pure . palindrome . words >>=
            print

-- Funcoes auxiliares

myIf :: Bool -> a -> a -> a
myIf True x y = x
myIf False x y = y

myLast :: [a] -> a
myLast [] = error "Lista vazia nao tem um ultimo elemento"
myLast (x : []) = x
myLast (x : xs) = myLast xs

myInit :: [a] -> [a]
myInit [] = error "Lista vazia nao tem um ultimo elemento"
myInit (x : []) = []
myInit (x : xs) = x : myInit xs

myDropWhile :: (a -> Bool) -> [a] -> [a]
myDropWhile p [] = []
myDropWhile p l@(x:xs) = myIf (p x) (myDropWhile p xs) l
