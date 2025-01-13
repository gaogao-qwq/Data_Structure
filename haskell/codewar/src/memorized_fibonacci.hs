fibonacci :: Int -> Integer
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci 2 = 1
fibonacci n = fibonacci' 2 1 1
  where
    fibonacci' i prev curr
      | i == n = curr
      | otherwise = fibonacci' (i + 1) curr (prev + curr)
