import           Data.Char       (isSpace)
import           Data.List
import qualified Data.Map.Strict as M
import           Data.Maybe      (isJust)

type Pos = (Int, Int)
type Cell = (Int, Int, Maybe Char)
type Grid = M.Map (Int, Int) (Maybe Char)

line :: [[Char]] -> Bool
line []  = False
line xss = undefined
  where end = findEnd xss

toGrid :: [[Char]] -> Grid
toGrid xss = foldl (\m (i, j, x) -> M.alter (\_ -> Just x) (i, j) m)
                   M.empty
                   [ (i, j, if isSpace x then Nothing else Just x)
                   | (i, xs) <- zip [0 .. ] xss
                   , (j, x) <- zip [0 .. ] xs ]

findEnd :: [[Char]] -> [Cell]
findEnd xss = [ (i, j, Just x)
              | (i, xs) <- zip [0 .. ] xss , (j, x) <- zip [0 .. ] xs
              , x == 'X' ]

findAdjacents :: Grid -> Pos -> [Cell]
findAdjacents grid (i, j) = [ case t of (Just t) -> (i - 1, j, t)
                                        _        -> (i - 1, j, Nothing)
                            , case r of (Just r) -> (i, j + 1, r)
                                        _        -> (i, j + 1, Nothing)
                            , case b of (Just b) -> (i + 1, j, b)
                                        _        -> (i + 1, j, Nothing)
                            , case l of (Just l) -> (i, j - 1, l)
                                        _        -> (i, j - 1, Nothing) ]
                            where t = grid M.!? (i - 1, j)
                                  r = grid M.!? (i, j + 1)
                                  b = grid M.!? (i + 1, j)
                                  l = grid M.!? (i, j - 1)
