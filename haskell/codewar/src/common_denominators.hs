type Ratio a = (a, a) -- Data.Ratio not suitable for this kata

convertFracs :: (Integral a) => [Ratio a] -> [Ratio a]
convertFracs xs = zipWith (\x y -> (fst x * y, snd x * y)) xs (multipliers $ map snd xs)

multipliers :: (Integral a) => [a] -> [a]
multipliers xs = [foldr lcm 1 xs `div` x | x <- xs]

