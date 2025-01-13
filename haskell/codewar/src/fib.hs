module Fib where

fibonacci :: Integer -> Integer
fibonacci n = fibonacci' 0 1 n

fibonacci' :: Integer -> Integer -> Integer -> Integer
fibonacci' _ b 1 = b
fibonacci' a b n = fibonacci' b (a + b) (n - 1)
