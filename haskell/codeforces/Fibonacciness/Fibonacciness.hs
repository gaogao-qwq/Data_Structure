-- https://codeforces.com/contest/2060/problem/A

module Main where
import           Control.Monad (replicateM)

main :: IO ()
main = do
  line <- getLine
  let t = read line :: Int
  lines <- replicateM t getLine
  let inputs = map (map read . words) lines :: [[Int]]
  putStrLn $ unlines (map (show . findMaxFib) inputs)

findMaxFib :: [Int] -> Int
findMaxFib [a1, a2, a4, a5] = maximum [fib [a1, a2, a3, a4, a5] | a3 <- [a1 + a2, a4 - a2, a5 - a4]]
  where
    fib :: [Int] -> Int
    fib []            = 0
    fib [x0]          = 0
    fib [x0, x1]      = 0
    fib (x0:x1:x2:xs) = if x2 == x0 + x1 then 1 + fib (x1:x2:xs) else fib(x1:x2:xs)
