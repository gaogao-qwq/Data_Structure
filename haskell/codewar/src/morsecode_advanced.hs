import           Data.List       (dropWhileEnd, group, nub, sort)
import           Data.List.Split (splitOn)
import           Data.Map        (Map, fromList, (!))
import           GHC.Base        (maxInt)

morseCodes :: Map String String
morseCodes = fromList [(".-", "0"), ("--.-", "1"), ("....", "H"), (".", "E"),
                       ("-.--", "Y"), (".---", "J"), ("..-", "U"), ("-..", "D"),
                       ("-", "T"), ("..", "I")]

-- 111 => ... (time unit unknown)
-- 000111000 => ... (time unit unknown)
-- 111000111 => .. (time unit = 3)
-- 1100000011 => . . (time unit = 2)
decodeBits :: String -> String
decodeBits bits = decodeBits' (group $ trimZero bits) (timeUnit $ trimZero bits) ""
  where decodeBits' :: [String] -> Maybe Int -> String -> String
        decodeBits' []       _  res = res
        decodeBits' (xs:xss) tm res
          | all (== '0') xs = decodeBits' xss tm $ res ++ parsePause xs tm
          | otherwise       = decodeBits' xss tm $ res ++ parseCode xs tm
        parsePause :: String -> Maybe Int -> String
        parsePause str Nothing    = ""
        parsePause str (Just tm)
          | length str == 7 * tm  = "   "
          | length str == 3 * tm  = " "
          | otherwise             = ""
        parseCode :: String -> Maybe Int -> String
        parseCode str Nothing    = "."
        parseCode str (Just tm)
          | length str == 3 * tm = "-"
          | otherwise            = "."

trimZero :: String -> String
trimZero s = dropWhile (== '0') $ dropWhileEnd (== '0') s

timeUnit :: String -> Maybe Int
timeUnit bits =
  let blens = map length (pauses bits)
      clens = map length (codes bits)
      bunit = case length blens of
              1 -> Just $ head blens
              2 -> Just (blens !! 1 `div` 3)
              3 -> Just (blens !! 2 `div` 7)
              _ -> Nothing
      cunit = case length clens of
              1 -> Just $ head clens
              2 -> Just (clens !! 1 `div` 3)
  in case (bunit, cunit) of
     (Nothing, Nothing) -> Nothing
     (Just b , Nothing) -> Just b
     (Nothing, Just c)  -> Just c
     (Just b , Just c)  -> Just $ min b c

codes :: String -> [String]
codes str = sort $ nub $ filter (all (== '1')) $ group str

pauses :: String -> [String]
pauses str = sort $ nub $ filter (all (== '0')) $ group str

dot :: String -> Int
dot str = let lens = map length (codes str)
          in if null lens then 0 else head lens

------------------------------------------------------------------------------
decodeMorse :: String -> String
decodeMorse s
  | null s = ""
  | otherwise = takeSpace s ++ ((morseCodes !) . takeMorse . dropSpace) s ++ (decodeMorse . dropMorse . dropSpace) s

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

trimSpace :: String -> String
trimSpace s = dropWhile (== ' ') $ dropWhileEnd (== ' ') s

