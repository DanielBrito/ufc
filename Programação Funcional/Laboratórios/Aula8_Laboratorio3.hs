module Aula8_Laboratorio3 where

import Aula3 (myIf)

-- Eu vou resolver a lista utilizando as funções já definidas no Prelude.

-- Reescreva myConcat usando foldr.

myConcat :: [[a]] -> [a]
myConcat = foldr (++) []

-- Reescreva myTakeWhile usando foldr.

myTakeWhile :: (a -> Bool) -> [a] -> [a]
myTakeWhile p = foldr f [] where
                f x ys = myIf (p x) (x:ys) []

-- Escreva a funcao myGroup, que recebe uma lista de elementos e retorna uma lista de listas, onde cada lista eh formada por elementos iguais e consecutivos da lista recebida.

myGroup :: Eq a => [a] -> [[a]]
myGroup = myGroupBy (==)

-- Agora vamos generalizar myGroup, fornecendo nosso proprio comparador. Como vc definiria myGroup em termos da funcao myGroupBy?

myGroupBy :: (a -> a -> Bool) -> [a] -> [[a]]
myGroupBy cmp [] = []
myGroupBy cmp (x:xs) = ys : myGroupBy cmp qs where
                       (ps, qs) = span (cmp x) xs
                       ys = x : ps

-- Deduza o que a funcao abaixo deve fazer e a escreva

myFind :: (a -> Bool) -> [a] -> Maybe a
myFind p [] = Nothing
myFind p (x:xs) = myIf (p x) (Just x) (myFind p xs)

-- Escreva as funcoes abaixo em termos de folds

myAny :: (a -> Bool) -> [a] -> Bool
myAny p = foldr f False where
          f x b = p x || b -- perceba como a ordem dos argumentos de (||) é importante.

myCycle :: [a] -> [a]
myCycle xs = foldr f [] [1..] where
             f y zs = xs ++ zs -- O y eh um elemento da lista [1..]. Repare como ele é ignorado.