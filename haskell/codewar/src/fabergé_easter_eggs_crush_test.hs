heigth :: Integer -> Integer -> Integer
heigth 0 _ = 0
heigth _ 0 = 0
heigth 1 m = m
heigth n m
  | n == m     = m ^ 2 - 1
  | n == m - 1 = m ^ 2 - 2
  | n == m - 2 = m ^ 2 - 2 - m
  | otherwise  = sum (scanl (\t i -> t * (m + 1 - i) `div` i) 1 [1..n]) - 1
