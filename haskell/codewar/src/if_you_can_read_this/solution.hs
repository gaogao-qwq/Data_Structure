module Codewars.Kata.IfYouCanReadThis (toNato) where

import Codewars.Kata.IfYouCanReadThis.Preload (nato)

import Data.Map.Strict (Map, fromList, (!))
import Data.Char (isAsciiLower, isAlpha, toUpper, isSpace)
import Data.List (dropWhileEnd)

toNato :: String -> String
toNato str = dropWhileEnd isSpace $ concatMap toNato' str
  where toNato' :: Char -> String
        toNato' c
          | isAlpha c = (nato ! toUpper c) ++ " "
          | isSpace c = ""
          | otherwise = c:" "

