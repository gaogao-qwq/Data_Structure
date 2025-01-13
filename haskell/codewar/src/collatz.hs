module Collatz where

-- One step of Collatz sequence
step :: Integer -> Integer
step x = if even x then down else up
 where
  down = div x 2
  up = 3 * x + 1

-- collatz x computes how many steps it takes for the Collatz sequence
-- to reach 1 when starting from x
collatz :: Integer -> Integer
collatz 1 = 0
collatz x = 1 + collatz (step x)

-- longest finds the number with the longest Collatz sequence for initial values
-- between 0 and upperBound
longest :: Integer -> Integer
longest upperBound = longest' 0 0 upperBound

-- helper function for longest
longest' :: Integer -> Integer -> Integer -> Integer
-- end of recursion, return longest length found
longest' number _ 0 = number
-- recursion step: check if n has a longer Collatz sequence than the current known longest
longest' number maxlength n =
  if len > maxlength
    then longest' n len (n - 1)
    else longest' number maxlength (n - 1)
 where
  len = collatz n
