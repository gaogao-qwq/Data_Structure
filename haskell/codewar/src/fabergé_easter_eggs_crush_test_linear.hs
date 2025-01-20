mo = 998244353

-- TODO: TLE
height :: Integer -> Integer -> Integer
height _ 0 = 0
height 0 _ = 0
height 1 m = m
height n m
  | n == m     = (m ^ 2 - 1) `mod` mo
  | n == m - 1 = (m ^ 2 - 2) `mod` mo
  | n == m - 2 = (m ^ 2 - 2 - m) `mod` mo
  | otherwise = let pre' = pre n 2 [0, 1]
                in foldl (\acc a -> (acc + a) `mod` mo) 0 (scanl (\t i -> (t * (m + 1 - i) * (pre' !! fromIntegral i)) `mod` mo) 1 [1..n]) - 1

pre :: Integer -> Integer -> [Integer] -> [Integer]
pre 1 _ res = res
pre n i res
  | i > n = res
  | otherwise = pre n (i + 1) (res ++ [(mo - (mo `div` i)) * (res !! fromIntegral (mo `mod` i)) `mod` mo])
