{-# LANGUAGE LambdaCase #-}
import           Data.List       (elemIndex, sortBy, maximumBy, maximum)
import           Data.Map.Strict (Map, alter, empty, filterWithKey, toList)
import           Data.Maybe      (fromMaybe)

chooseMove :: [Int] -> (Int, Int)
chooseMove [x] = (0, x)
chooseMove xs =
  case oddCounts xs of
  (Nothing, Nothing)     -> (elemIndex (maximum xs), maximum xs)
  (Just cnt, Nothing)    -> (fromMaybe 0 (elemIndex cnt xs), cnt)
  (Just cnt0, Just cnt1) -> (fromMaybe 0 (elemIndex cnt0 xs), cnt0 - cnt1)

oddCounts :: [Int] -> (Maybe Int, Maybe Int)
oddCounts xs =
  let counts = sortBy (\(k0, _) (k1, _) -> compare k1 k0)
               $ toList $ filterWithKey (\k v -> odd v) (getCount xs)
  in ( if null counts || null (head counts)
       then Nothing
       else Just (fst $ head counts)
     , if null counts || null (tail counts)
       then Nothing
       else Just (fst $ counts !! 1) )

getCount :: [Int] -> Map Int Int
getCount [] = empty
getCount (x:xs)
  | x == 0 = getCount xs
  | otherwise = alter (\ case
                         Just cnt -> Just (cnt + 1)
                         Nothing -> Just 1) x $ getCount xs

