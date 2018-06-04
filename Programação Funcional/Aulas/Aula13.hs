module Aula13 where

fibs :: Int -> Int
fibs 0 = 0
fibs 1 = 1
fibs n = fibs (n - 1) + fibs(n - 2)

fib' :: Int -> Int
fib' = ((map memo [0..]) !!) where
  memo 0 = 0
  memo 1 = 1
  memo n = fib' (n - 1) + fib' (n - 2)