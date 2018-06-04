module BSTree (empty, search, insert, delete, inOrderWalk, preOrderWalk, postOrderWalk, foldTree) where

{-

import BSTRee as BST
kvs = zip [1,4,3,6,2,6,2,6,12,4,7,3,2,7,4] "ajkfhdjlkehwycanspoqwea"
tree = foldl BST.insert BST.empty kvs
BST.search tree 4

-}

import Aula3 (myIf)

data BSTree k v = Empty
                | Branch (k, v) (BSTree k v) (BSTree k v)

empty :: BSTree k v
empty = Empty

data MyOrdering = L | E | G

myCompare :: Ord a => a -> a -> MyOrdering
myCompare x y = myIf (x == y) E (myIf (x < y) L G)

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

insert :: Ord k => BSTree k v -> (k, v) -> BSTree k v
insert Empty (key, val) = Branch (key, val) Empty Empty
insert bst@(Branch (key', val') lb rb) (key, val) =
        decide (myCompare key key') where
        decide E = bst
        decide L = Branch (key', val') lb' rb
        decide G = Branch (key', val') lb rb'
        lb' = insert lb (key, val)
        rb' = insert rb (key, val)

search :: Ord k => BSTree k v -> k -> Maybe v
search Empty key = Nothing
search (Branch (key', val') lb rb) key =
        decide (myCompare key key') where
        decide E = Just val'
        decide L = search lb key
        decide G = search rb key

maxKey :: BSTree k v -> Maybe (k, v)
maxKey Empty = Nothing
maxKey (Branch keyval _ Empty) = Just keyval
maxKey (Branch keyval _ rb) = maxKey rb

minKey :: BSTree k v -> Maybe (k, v)
minKey Empty =Nothing
minKey (Branch keyval Empty _) = Just keyval
minKey (Branch keyval lb _) = minKey lb

delete :: Ord k => BSTree k v -> k -> BSTree k v
delete Empty key = Empty
delete bst@(Branch (key', val') Empty Empty) key =
        decide (myCompare key key') where
        decide E = Empty
        decide _ = bst
delete bst@(Branch (key', val') lb Empty) key =
        decide (myCompare key key') where
        decide E = lb
        decide G = bst
        decide L = Branch (key', val') lb' Empty
        lb' = delete lb key
delete bst@(Branch (key', val') Empty rb) key =
        decide (myCompare key key') where
        decide E = rb
        decide L = bst
        decide G = Branch (key', val') Empty rb'
        rb' = delete rb key
delete (Branch (key', val') lb rb) key =
        decide (myCompare key key') where
        decide L = Branch (key', val') lb' rb
        decide G = Branch (key', val') lb rb'
        decide E = myIf (isEmpty rlb)
                        (Branch rbKeyVal lb rrb)
                        (Branch (key'', val'') lb rb'')
        lb' = delete lb key
        rb' = delete rb key
        Just rlb = lBranch rb
        Just rbKeyVal = keyVal rb
        Just rrb = rBranch rb
        Just (key'', val'') = minKey rb
        rb'' = delete rb key''

preOrderWalk :: BSTree k v -> [(k, v)] -- R | E | D
preOrderWalk Empty = []
preOrderWalk (Branch (k, v) Empty rb) = [(k, v)] ++ preOrderWalk (rb)
preOrderWalk (Branch (k, v) lb Empty) = [(k, v)] ++ preOrderWalk (lb)
preOrderWalk (Branch (k, v) lb rb) =  [(k, v)] ++ preOrderWalk (lb) ++ preOrderWalk (rb)

inOrderWalk :: BSTree k v -> [(k, v)] -- E | R | D
inOrderWalk Empty = []
inOrderWalk (Branch (k, v) Empty rb) = [(k, v)] ++ inOrderWalk (rb)
inOrderWalk (Branch (k, v) lb Empty) = inOrderWalk (lb) ++ [(k, v)]
inOrderWalk (Branch (k, v) lb rb) = inOrderWalk (lb) ++ [(k, v)] ++ inOrderWalk (rb)

postOrderWalk :: BSTree k v -> [(k, v)] -- E | D | R
postOrderWalk Empty = []
postOrderWalk (Branch (k, v) Empty rb) = postOrderWalk (rb) ++ [(k, v)]
postOrderWalk (Branch (k, v) lb Empty) = postOrderWalk (lb) ++ [(k, v)]
postOrderWalk (Branch (k, v) lb rb) = postOrderWalk (lb) ++ postOrderWalk (rb) ++ [(k, v)]

foldTree :: (a -> b -> a) -> a -> BSTree k b -> a
foldTree f x Empty = x
foldTree f x (Branch (k, v) Empty rb) = y where
                                        y = (foldTree f (f x v) rb)
foldTree f x (Branch (k, v) lb Empty) = z where
                                        z = (foldTree f (f x v) lb)
foldTree f x (Branch (k, v) lb rb) = w where
                                     w = (foldTree f (foldTree f (f x v) lb) rb)

update :: (Ord k) => BSTree k v -> k -> (v -> v) -> BSTree k v
update = undefined