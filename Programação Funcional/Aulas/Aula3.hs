module Aula3 where

import Aula2 (myReverse)

myTake :: Int -> [a] -> [a]
myTake n [] = []
myTake 0 (x:xs) = []
myTake n (x:xs) = x : myTake (n - 1) xs

myIf :: Bool -> a -> a -> a
myIf True x y = x
myIf False x y = y

myDrop :: Int -> [a] -> [a]
myDrop n [] = []
myDrop 0 l@(x:xs) = l
myDrop n (x:xs) = myDrop (n - 1) xs

mySplitAt :: Int -> [a] -> ([a], [a])
mySplitAt n xs = (myTake n xs, myDrop n xs)

myIsPrefixOf :: Eq a => [a] -> [a] -> Bool
myIsPrefixOf [] ys = True
myIsPrefixOf (x:xs) [] = False
myIsPrefixOf (x:xs) (y:ys) = myIf (x == y) (myIsPrefixOf xs ys) False

myIsSuffixOf :: Eq a => [a] -> [a] -> Bool
myIsSuffixOf xs ys = (myReverse xs) `myIsPrefixOf` (myReverse ys)

myIsInfixOf :: Eq a => [a] -> [a] -> Bool
myIsInfixOf [] ys = True
myIsInfixOf (x:xs) [] = False
myIsInfixOf l@(x:xs) (y:ys) = myIf (x == y) (myIsPrefixOf xs ys) (myIsInfixOf l ys)