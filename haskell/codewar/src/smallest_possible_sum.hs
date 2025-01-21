smallestPossibleSum :: (Integral a) => [a] -> a
smallestPossibleSum []     = 0
smallestPossibleSum (x:xs) = fromIntegral (length (x:xs)) * foldl gcd x xs
