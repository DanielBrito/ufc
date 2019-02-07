quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = smallerSorted ++ [x] ++ biggerSorted where
    smallerSorted = quicksort [a | a <- xs, a <= x]
    biggerSorted  = quicksort [a | a <- xs, a > x]