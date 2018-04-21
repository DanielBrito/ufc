module Aula9 where

myMap :: (a -> b) -> [a] -> [b]
myMap f = foldr g [] where
          g x acc = f x : acc
          
inutil :: [a] -> [a]
inutil xs = foldr (:) [] xs

myId :: a -> a
myId x = x

myConcat :: [a] -> [a] -> [a]
myConcat = foldr (:)
