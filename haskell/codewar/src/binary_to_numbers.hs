toNumber :: [Int] -> Int
toNumber = foldl (\acc b -> 2 * acc + b) 0
-- toNumber b = toNumber' b (length b - 1)
--   where toNumber' :: [Int] -> Int -> Int
--         toNumber' [] _ = 0
--         toNumber' b' n = head b' * 2 ^ n + (toNumber' . tail) b' (n - 1)
