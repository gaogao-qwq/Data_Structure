import Data.List
import Data.Map (Map, fromList)
import Data.Map.Strict ((!))

morseCodes :: Map String String
morseCodes = fromList [(".-", "0"), ("--.-", "1")]

trimSpace :: String -> String
trimSpace s = dropWhile (== ' ') $ dropWhileEnd (== ' ') s

takeSpace :: String -> String
takeSpace s =
  if takeWhile (== ' ') s == "   "
  then " "
  else ""

dropSpace :: String -> String
dropSpace = dropWhile (== ' ')

dropMorse :: String -> String
dropMorse = dropWhile (/= ' ')

takeMorse :: String -> String
takeMorse = takeWhile (/= ' ')

-- "   .- .- .- .-   --.-  "
-- => "0000 1"
decodeMorse :: String -> String
decodeMorse s = decodeMorse' $ trimSpace s
  where decodeMorse' s
         | null s = ""
         | otherwise = takeSpace s ++ ((morseCodes !) . takeMorse . dropSpace) s ++ (decodeMorse' . dropMorse . dropSpace) s
