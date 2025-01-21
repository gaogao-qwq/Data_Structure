import           Test.Hspec (hspec, describe, it, shouldBe)
import           Test.QuickCheck (property, forAll, listOf, elements)

-- 你要测试的函数
stringLength :: String -> Int
stringLength = length

main :: IO ()
main = hspec $ do
  describe "stringLength" $ do
    it "returns the length of a string" $
      property $ forAll (listOf $ elements (['a'..'z'] ++ ['A'..'Z'] ++ [',', '.', '!', '?'])) $ \str -> do
        putStrLn str
        stringLength str `shouldBe` length str

