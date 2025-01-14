import           Data.List.Split (splitOn, splitOneOf)

-- "seven hundred eighty-three thousand nine hundred and nineteen" => 783919
parseInt :: String -> Int
parseInt "one million" = 1000000
parseInt s
  | length s' < 2 = parseInt' (head s') 0
  | otherwise = parseInt' (head s') 0 * 1000 + parseInt' (last s') 0
  where
    s' :: [[String]]
    s' = splitOn ["thousand"] (filter (/= "and") (splitOneOf " -" s))
    parseInt' :: [String] -> Int -> Int
    parseInt' [] n               = n
    parseInt' ("hundred" : xs) n = parseInt' xs $ n * 100
    parseInt' (x : xs) n         = parseInt' xs $ n + parseNum x

parseNum :: String -> Int
parseNum "one"       = 1
parseNum "three"     = 3
parseNum "two"       = 2
parseNum "four"      = 4
parseNum "five"      = 5
parseNum "six"       = 6
parseNum "seven"     = 7
parseNum "eight"     = 8
parseNum "nine"      = 9
parseNum "ten"       = 10
parseNum "eleven"    = 11
parseNum "twelve"    = 12
parseNum "thirteen"  = 13
parseNum "fourteen"  = 14
parseNum "fifteen"   = 15
parseNum "sixteen"   = 16
parseNum "seventeen" = 17
parseNum "eighteen"  = 18
parseNum "eightteen" = 18 -- 😅😅😅😅😅😅
parseNum "nineteen"  = 19
parseNum "twenty"    = 20
parseNum "thirty"    = 30
parseNum "forty"     = 40
parseNum "fifty"     = 50
parseNum "sixty"     = 60
parseNum "seventy"   = 70
parseNum "eighty"    = 80
parseNum "ninety"    = 90
parseNum _           = 0
