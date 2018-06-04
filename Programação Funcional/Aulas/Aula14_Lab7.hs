module Aula14 where

import Control.Applicative
import Control.Monad

import Data.Char

-- Questao 1
-- Escreva uma funcao que calcula o produto cartesiano de duas listas
-- Ex: dadas [1, 2] e ['a', 'b'] como entrada, devemos retornar [(1, 'a'), (1, 'b'), (2, 'a'), (2, 'b')]

-- Dica: muito fácil usando <$> e <*>

cartesian :: [a] -> [b] -> [(a, b)]
cartesian xs ys = (,) <$> xs <*> ys

-- Vamos implementar um cara analogo ao Maybe

data Option a = None | Some a deriving Show

-- Questao 2
-- Faca Option uma instancia de Functor.

instance Functor Option where
    fmap _ None = None
    fmap f (Some a) = Some (f a)
    -- (+1) <$> (Some 3)

-- Questao 3
-- Faca Option uma instancia de Applicative.
instance Applicative Option where  
    pure = Some  
    None <*> _ = None  
    (Some f) <*> something = fmap f something
    -- Some (+3) <*> Some 2
    -- Testar (+3) <* Some 2
    -- Testar (+3) *> Some 2

-- Questao 4
-- Faca Option uma instancia de Alternative.
instance Alternative Option where
  empty               = None
  None <|> None       = None
  Some x  <|> None    = Some x
  None <|> Some x     = Some x
  Some x  <|> Some y  = Some x 
--Some 4 <|> None

-- Questao 5
-- Essa funcao existe em Control.Applicative
-- Dada uma lista de funtores aplicativos, retorne um funtor aplicativo contendo uma lista.

mySequenceA :: Applicative f => [f a] -> f [a]
mySequenceA [] = pure []
mySequenceA (x:xs) = (:) <$> x <*> mySequenceA xs
--mySequenceA [(Some 4), (Some 5), (Some 6)]
