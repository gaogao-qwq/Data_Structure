import           Data.List (permutations, sort, sortBy, uncons)
--   12 ==> 21
--  513 ==> 531
-- 2017 ==> 2071
-- 2637186 => 2637618

--   9 ==> -1
-- 111 ==> -1
-- 531 ==> -1

nextBigger :: Int -> Int
nextBigger n = if n < 10 || sortBy (flip compare) (show n) == show n then -1 else read $ findNext $ show n

findNext :: String -> String
findNext s = findNext' s 2
  where
    findNext' :: String -> Int -> String
    findNext' s n
      | n > length s = s
      | otherwise = let next = uncons $ sort $ filter (> drop(length s - n) s) (permutations $ drop (length s - n) s)
                    in case next of
                    Nothing     -> findNext' s (n + 1)
                    Just(x, xs) -> take (length s - n) s ++ x

