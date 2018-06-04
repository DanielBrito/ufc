module Aula12 where

import System.Environment (getArgs)

{-

import BSTree as BST

-- Escreva as funcoes de passeio nas arvores no arquivo BSTree.hs, e as exporte.

preOrderWalk :: BSTree k v -> [(k, v)]
preOrderWalk = undefined

inOrderWalk :: BSTree k v -> [(k, v)]
inOrderWalk = undefined

postOrderWalk :: BSTree k v -> [(k, v)]
postOrderWalk = undefined

-- Escreva um fold para arvores, tambem no arquivo BSTree.hs, e o exporte. Vc consegue imaginar mais de um fold?

foldTree :: (a -> b -> a) -> a -> BSTree k b -> a
foldTree = undefined

-- Escreva a funcao abaixo, que atualiza o elemento associado a uma chave de acordo com uma funcao.
-- Escreva no arquivo BSTree.hs e a exporte.

update :: (Ord k) => BSTree k v -> k -> (v -> v) -> BSTree k v
update = undefined

-}

main :: IO ()
main = program1

-- O que esse programa faz?

program1 :: IO ()
program1 =  getArgs                   >>=
            pure . head               >>=
            readFile                  >>=
            pure . (map head) . words >>=
            print

-- Escreva um programa que imprime quantas vezes cada palavra aparece em um arquivo dado como entrada.
-- Perceba como vai ser util utilizar BSTree, search, insert, update e um dos passeios.

program2 :: IO ()
program2 = undefined