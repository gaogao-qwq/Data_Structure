-- https://en.wikipedia.org/wiki/Integer_partition#Partition_function
-- https://en.wikipedia.org/wiki/Pentagonal_number
import           Data.Map.Strict (Map, fromList, insert, (!))

type Memo = (Map Integer Integer)

explosiveSum :: Integer -> Integer
explosiveSum 0 = 1
explosiveSum 1 = 1
explosiveSum n = go (fromList [(0, 1), (1, 1)]) n 2
  where
    go :: Memo -> Integer -> Integer -> Integer
    go m n i
      | n == i = partitions m n
      | otherwise = go (insert i (partitions m i) m) n (i + 1)

partitions :: Memo -> Integer -> Integer
partitions m n = foldl
                  (\ acc a ->
                     acc + if odd $ ceiling $ fromIntegral (fst a) / 2.0
                           then m ! (n - snd a)
                           else -(m ! (n - snd a)) )
                  0 $ zip [1..] (takeWhile (<= n) $ map pentagonal [1..])

pentagonal :: Integer -> Integer
pentagonal n = let n' = ceiling (fromIntegral n / 2.0)
               in (3 * n' * n' + if odd n then -n' else n') `div` 2
