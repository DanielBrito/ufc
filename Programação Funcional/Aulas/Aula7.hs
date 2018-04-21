module Aula7 where

import Aula3 (myIf)

myUncurry :: (a -> b -> c) -> (a, b) -> c
myUncurry f (x, y) = f x y

myMap :: (a -> b) -> [a] -> [b]
myMap f [] = []
myMap f (x:xs) = f x : myMap f xs

myZipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
myZipWith f [] ys = []
myZipWith f xs [] = []
myZipWith f (x:xs) (y:ys) = f x y : myZipWith f xs ys

myZip = myZipWith (,)

myFoldl :: (a -> b -> a) -> a -> [b] -> a
myFoldl f x [] = x
myFoldl f x (y:ys) = myFoldl f (f x y) ys

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr f x [] = x
myFoldr f x (y:ys) = f y (myFoldr f x ys)

myFilter p xs = myFoldr f [] xs where
                f x ys = myIf (p x) (x:ys) ys







