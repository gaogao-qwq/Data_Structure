import Data.Map (Map, fromList)
import Data.Map.Strict ((!))

roman = fromList [(1, 'I'), (5, 'V'), (10, 'X'), (50, 'L'), (100, 'C'), (500, 'D'), (1000, 'M')]
fmt = fromList [(1, "A"), (2, "AA"), (3, "AAA"), (4, "AB"), (5, "B"), (6, "BA"), (7, "BAA"), (8, "BAAA"), (9, "AC"), (0, "")]

rtos :: Integer -> Integer -> String
rtos 0 _ = ""
rtos d n = map rtos' (fmt ! n)
 where
  rtos' :: Char -> Char
  rtos' 'A' = roman ! (d + 0 * d)
  rtos' 'B' = roman ! (d + 4 * d)
  rtos' 'C' = roman ! (d + 9 * d)

solution :: Integer -> String
solution n = step 1 n ""
 where
  step :: Integer -> Integer -> String -> String
  step _ 0 s = s
  step d n s = step (d * 10) (n `div` 10) (rtos d (n `mod` 10) ++ s)
