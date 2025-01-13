getUnique :: [Int] -> Int
getUnique arr
  | head arr /= arr !! 1 && head arr /= arr !! 2 = head arr
  | otherwise = head $ filter (/= head arr) arr
