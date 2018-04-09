module Main where

main :: IO ()
main = print (f 2 (1 + 1))

f :: Int -> Int -> Int
f x y = x + y
