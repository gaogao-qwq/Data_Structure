import Data.Char (isAsciiLower)

toCamelCase :: String -> String
toCamelCase "" = ""
toCamelCase s = (head . words . map replaceDelim) s ++ concatMap uppercase ((tail . words . map replaceDelim) s)
  where replaceDelim :: Char -> Char
        replaceDelim c
         | c == '_' || c == '-' = ' '
         | otherwise = c
        uppercase :: String -> String
        uppercase s = (if isAsciiLower (head s) then toEnum (fromEnum (head s) - 32) else head s) : tail s
