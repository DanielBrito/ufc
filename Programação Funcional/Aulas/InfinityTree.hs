module InfinityTree
    (constant,
     naturalsTree,
     toList,
     find
    ) where

import Aula3 (myIf)

data InfinityTree a = Branch a (InfinityTree a) (InfinityTree a)

constant :: a -> InfinityTree a
constant x = Branch x treeX treeX where
  treeX = constant x

instance Eq a => Eq (InfinityTree a) where
  Branch x lTreeX rTreeX == Branch y lTreeY rTreeY =
    (x == y) && (lTreeX == lTreeY) && (rTreeX == rTreeY)

instance Functor InfinityTree where
  fmap f (Branch x lb rb) = Branch x' lb' rb' where
    x' = f x
    lb' = fmap f lb
    rb' = fmap f rb

instance Applicative InfinityTree where
  pure = constant
  (Branch f lTreeF rTreeF) <*> (Branch x lTreeX rTreeX) =
    Branch (f x) (lTreeF <*> lTreeX) (rTreeF <*> rTreeX)

naturalsTree :: InfinityTree Int
naturalsTree = Branch 0 lb rb where
               lb = ((+1) . (*2)) <$> naturalsTree
               rb = ((+2) . (*2)) <$> naturalsTree

toList :: InfinityTree a -> [a]
toList (Branch x lb rb) = x : alternate lb' rb' where
                lb' = toList lb
                rb' = toList rb
                alternate [] [] = []
                alternate xs [] = xs
                alternate [] ys = ys
                alternate (x:xs) (y:ys) = x : y : alternate xs ys

find :: InfinityTree a -> Int -> a
find (Branch x lb rb) 0 = x
find (Branch x lb rb) n = myIf (even n)
                               (find rb n')
                               (find lb n'') where
                                 n' = (n - 2) `div` 2
                                 n'' = (n - 1) `div` 2

memofib :: Int-> Int
memofib = find fibTree where
          fibTree = fib <$> naturalsTree
          fib 0 = 0
          fib 1 = 1
          fib n = (memofib (n - 1)) + (memofib (n - 2))

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)
