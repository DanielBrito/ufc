module Aula5 where

import Aula3 (myIf)

mySum :: Num a => (a, a) -> a
mySum (x, y) = x + y

myAndPred :: (a -> Bool) -> (a -> Bool) -> a -> Bool
myAndPred p q x = (p x) && (q x)

myNot :: Bool -> Bool
myNot True = False
myNot False = True

myZip :: [a] -> [b] -> [(a, b)]
myZip xs [] = []
myZip [] ys = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myTakeWhile :: (a -> Bool) -> [a] -> [a]
myTakeWhile p [] = []
myTakeWhile p (x:xs) = myIf (p x) (x : myTakeWhile p xs) []

myDropWhile :: (a -> Bool) -> [a] -> [a]
myDropWhile p [] = []
myDropWhile p l@(x:xs) = myIf (p x) (myDropWhile p xs) l

mySpan :: (a -> Bool) -> [a] -> ([a], [a])
mySpan p [] = ([], [])
mySpan p l@(x:xs) = myIf (p x) (x : ms, ns) ([], l) where
                    (ms, ns) = mySpan p xs

comp :: (b -> c) -> (a -> b) -> a -> c
comp f g x = f (g x)

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter p [] = []
myFilter p (x:xs) = myIf (p x) (x : ms) ms where
                    ms = myFilter p xs


















