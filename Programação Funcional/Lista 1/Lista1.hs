module Lista1 where

myIf :: Bool -> a -> a -> a
myIf True x y = x
myIf False x y = y

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr f x [] = x
myFoldr f x (y : ys) = f y (myFoldr f x ys)

------------------- Questao 1 ---------------------

uncons :: [a] -> Maybe (a,[a])
uncons [] = Nothing
uncons (x : xs) = Just (x, xs)

------------------- Questao 2 ---------------------

myIterate :: (a -> a) -> a -> [a]
myIterate f x = [x] ++ myIterate f (f x)

------------------- Questao 3 ---------------------

myReplicate :: Int -> a -> [a]
myReplicate 0 x = []
myReplicate n x = x : myReplicate (n - 1) x 

------------------- Questao 4 ---------------------

myGroup :: Eq a => [a] -> [[a]]
myGroup = myGroupBy (==)

myGroupBy :: (a -> a -> Bool) -> [a] -> [[a]]
myGroupBy cmp [] = []
myGroupBy cmp (x:xs) = ys : myGroupBy cmp qs where
                       (ps, qs) = span (cmp x) xs
                       ys = x : ps

------------------- Questao 5 ---------------------

inits :: [a] -> [[a]]
inits [] = [[]]
inits (x : xs) = [[]] ++ map (x:) (inits xs)

------------------- Questao 6 ---------------------

tails :: [a] -> [[a]]
tails [] = [[]]
tails l@(x : xs) = l : tails xs
 
------------------- Questao 7 ---------------------

isSubsequenceOf :: (Eq a) => [a] -> [a] -> Bool
isSubsequenceOf [] xs = True
isSubsequenceOf xs [] = False
isSubsequenceOf l@(x : xs) (y : ys) = myIf(x == y) (isSubsequenceOf xs ys) (isSubsequenceOf l ys)


 ------------------- Questao 8 ---------------------

find :: (a -> Bool) -> [a] -> Maybe a
find f [] = Nothing
find f (x : xs) = myIf (f x) (Just x) (find f xs)

------------------- Questao 9 ---------------------

insert :: (Ord a) => a -> [a] -> [a]
insert x [] = [x]
insert x (y : ys) = myIf(x < y) (x : y : ys) (y : insert x ys) 

insertionSort :: (Ord a) => [a] -> [a]
insertionSort [] = []
insertionSort [x] = [x]
insertionSort (x : xs) = insert x (insertionSort xs)

------------------- Questao 10 ---------------------

myId :: [a] -> [a]
myId = foldr (:) []

myAnd :: [Bool] -> Bool
myAnd = foldr (&&) True

myOr :: [Bool] -> Bool
myOr = foldr (||) False

myMap :: (a -> b) -> [a] -> [b]
myMap f = foldr ((:).f) []