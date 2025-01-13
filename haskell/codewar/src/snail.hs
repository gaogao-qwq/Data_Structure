import Data.List (transpose)

-- array = [[1,2,3],
--          [8,9,4],
--          [7,6,5]]
-- snail(array) #=> [1,2,3,4,5,6,7,8,9]
snail :: [[Int]] -> [Int]
snail [] = []
snail (xs:xss) = xs ++ (snail . reverse . transpose) xss

-- snail :: [[Int]] -> [Int]
-- snail [[]] = []
-- snail mat = right mat
--
-- right :: [[Int]] -> [Int]
-- right [] = []
-- right mat = head mat ++ down (tail mat)
--
-- down :: [[Int]] -> [Int]
-- down [] = []
-- down mat = map last mat ++ left (map (take $ length (head mat) - 1) mat)
--
-- left :: [[Int]] -> [Int]
-- left [] = []
-- left mat = reverse (last mat) ++ up (take (length mat - 1) mat)
--
-- up :: [[Int]] -> [Int]
-- up [] = []
-- up mat = reverse (map head mat) ++ right (map tail mat)
