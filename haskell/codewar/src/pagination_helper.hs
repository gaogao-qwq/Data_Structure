type Collection a = [a]
type ItemsPerPage = Int

itemCount :: Collection a -> Int
itemCount = length

pageCount :: Collection a -> ItemsPerPage -> Int
pageCount xs 0 = 0
pageCount xs n = ceiling $ (fromIntegral . itemCount) xs / fromIntegral n

pageItemCount :: Collection a -> ItemsPerPage -> Int -> Maybe Int
pageItemCount xs n page
  | page < 0 = Nothing
  | page >= pageCount xs n = Nothing
  | page == pageCount xs n - 1 = Just $ if itemCount xs `mod` n == 0 then n else itemCount xs `mod` n
  | otherwise = Just n

pageIndex :: Collection a -> ItemsPerPage -> Int -> Maybe Int
pageIndex xs n item
  | item < 0 = Nothing
  | item >= itemCount xs = Nothing
  | otherwise = Just $ item `div` n
