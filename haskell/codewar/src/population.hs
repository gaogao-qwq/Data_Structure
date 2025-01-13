nbYear :: Int -> Double -> Int -> Int -> Int
nbYear p0 percent aug p = nbYear' p0 percent aug p 0
  where nbYear' p0 percent aug p res =
          if p0 < p
          then nbYear' (calc p0 percent aug) percent aug p (res + 1)
          else res
        calc p0 percent aug = p0 + floor (fromIntegral p0 * percent / 100) + aug
