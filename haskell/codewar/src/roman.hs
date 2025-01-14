import           Data.Map        (Map, fromList)
import           Data.Map.Strict ((!))

roman :: Map Char Int
roman = fromList [('I', 1), ('V', 5), ('X', 10), ('L', 50), ('C', 100), ('D', 500), ('M', 1000)]

subnot :: Char -> Char -> Bool
subnot 'I' 'V' = True -- 4
subnot 'I' 'X' = True -- 9
subnot 'X' 'L' = True -- 40
subnot 'X' 'C' = True -- 90
subnot 'C' 'D' = True -- 400
subnot 'C' 'M' = True -- 900
subnot _ _     = False

-- "MM"      -> 2000
-- "MDCLXVI" -> 1666
-- "M"       -> 1000
-- "CD"      ->  400
-- "XC"      ->   90
-- "XL"      ->   40
-- "I"       ->    1
solution :: String -> Int
solution s = step s 0
 where
  step :: String -> Int -> Int
  step s n
    | null s = n
    | length s < 2 = n + roman ! head s
    | otherwise =
        if subnot (head s) (s !! 1)
          then n + step (tail $ tail s) (roman ! (s !! 1) - roman ! head s)
          else n + step (tail s) (roman ! head s)
