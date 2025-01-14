import           GHC.Float (powerFloat)

-- https://mathworld.wolfram.com/Factorial.html
zeros :: Int -> Int
zeros 0 = 0
zeros n = d + zeros d
  where d = div n 5
-- zeros n = zeros' 1
--   where
--     zeros' :: Int -> Int
--     zeros' k
--       | k > floor (logBase 5 $ fromIntegral n) = 0
--       | otherwise = n `div` floor (powerFloat 5 $ fromIntegral k) + zeros' (k + 1)
