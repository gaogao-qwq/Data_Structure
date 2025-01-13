findEvenIndex :: [Int] -> Int
findEvenIndex arr = comp 0
  where
    comp :: Int -> Int
    comp n
      | n > length arr = -1
      | sum (take n arr) == sum (drop (n + 1) arr) = n
      | otherwise = comp (n + 1)
