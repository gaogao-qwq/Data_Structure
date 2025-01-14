humanReadable :: Int -> String
humanReadable x = concatMap padd [show (x `div` 3600), ":", show (x `div` 60 `mod` 60), ":", show (mod x 60)]
  where
    padd :: String -> String
    padd ":"      = ":"
    padd [x]      = '0' : [x]
    padd (x : xs) = x : xs
