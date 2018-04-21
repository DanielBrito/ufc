module BSTree where

import Aula3 (myIf)

data BSTree k v = Empty
                | Branch (k, v) (BSTree k v) (BSTree k v)

keyVal :: BSTree k v -> Maybe (k, v)
keyVal Empty = Nothing
keyVal (Branch kv _ _) = Just kv

lBranch :: BSTree k v -> Maybe (BSTree k v)
lBranch Empty = Nothing
lBranch (Branch _ lb _) = Just lb

rBranch :: BSTree k v -> Maybe (BSTree k v)
rBranch Empty = Nothing
rBranch (Branch _ _ rb) = Just rb

isEmpty :: BSTree k v -> Bool
isEmpty Empty = True
isEmpty _ = False

isBranch :: BSTree k v -> Bool
isBranch = not . isEmpty

insert :: Ord k => BSTree k v -> k -> v -> BSTree k v
insert Empty key val = Branch (key, val) Empty Empty
insert bst@(Branch (key', val') lb rb) key val =
       myIf (key == key') bst (myIf (key < key') lbst rbst) where
       lbst = insert lb key val
       rbst = insert rb key val
      










