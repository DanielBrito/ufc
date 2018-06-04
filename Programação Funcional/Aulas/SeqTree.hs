module SeqTree (empty,
                isEmpty,
                search,
                insert,
                update,
                remove) where

import Aula3 (myIf)

data SeqTree a = Empty
               | Leaf a
               | Branch Int Int (SeqTree a) (SeqTree a)

empty :: SeqTree a
empty = Empty

height :: SeqTree a -> Int
height Empty = 0
height (Leaf x) = 0
height (Branch s h lb rb) = h

size :: SeqTree a -> Int
size Empty = 0
size (Leaf x) = 1
size (Branch s h lb rb) = s

lBranch ::SeqTree a -> SeqTree a
lBranch Empty = Empty
lBranch (Leaf x) = Empty
lBranch (Branch s h lb rb) = lb

rBranch ::SeqTree a -> SeqTree a
rBranch Empty = Empty
rBranch (Leaf x) = Empty
rBranch (Branch s h lb rb) = rb

makeBranch :: SeqTree a -> SeqTree a -> SeqTree a
makeBranch lb rb = Branch s h lb rb where
                   s = (size lb) + (size rb)
                   h = (max (height lb) (height rb)) + 1

isEmpty :: SeqTree a -> Bool
isEmpty Empty = True
isEmpty _ = False

search :: SeqTree a -> Int -> Maybe a
search Empty n = Nothing
search (Leaf x) 1 = Just x
search (Leaf x) n = Nothing
search branch n = myIf (n <= slb)
                       (search lb n)
                       (search rb (n - slb)) where
                  lb = lBranch branch
                  rb = rBranch branch
                  slb = size lb

data Positioning = LL | GL | GG

myCmp :: Ord a => a -> a -> a -> Positioning
myCmp x p q = myIf (p > q)
                   (myCmp x q p)
                   (myIf (x < p)
                         LL
                         (myIf (x < q)
                               GL
                               GG))

insert :: SeqTree a -> a -> SeqTree a
insert Empty y = Leaf y
insert lx@(Leaf x) y = makeBranch lx (Leaf y)
insert branch x =
        decide (myCmp (size branch) (2^hlb) (2^h)) where
        decide LL = makeBranch (insert lb x) rb
        decide GL = makeBranch lb (insert rb x)
        decide GG = makeBranch branch (Leaf x)
        h = height branch
        hlb = height lb
        lb = lBranch branch
        rb = rBranch branch
        
update :: SeqTree a -> Int -> a -> SeqTree a
update Empty n y = Empty
update (Leaf x) 1 y = Leaf y
update st@(Leaf x) n y = st
update branch n y = myIf (n > size branch)
                         branch
                         (myIf (n <= slb)
                               (makeBranch lb' rb)
                               (makeBranch lb rb')) where
                    lb = lBranch branch
                    rb = rBranch branch
                    lb' = update lb n y
                    rb' = update rb n' y
                    slb = size lb
                    n' = n - slb

remove :: SeqTree a -> SeqTree a
remove Empty = Empty
remove (Leaf x) = Empty
remove branch = myIf (isEmpty rb)
                     (remove lb)
                     (makeBranch lb rb') where
                lb = lBranch branch
                rb = rBranch branch
                rb' = remove rb