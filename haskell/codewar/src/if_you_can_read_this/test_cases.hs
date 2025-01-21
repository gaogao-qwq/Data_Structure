module Codewars.Kata.IfYouCanReadThisSpec where

import Codewars.Kata.IfYouCanReadThis (toNato)
import Codewars.Kata.IfYouCanReadThis.Preload (nato)

import Test.Hspec
import Test.QuickCheck
import Data.Map.Strict (Map, fromList, (!))
import Data.Char (isAsciiLower, isAlpha, toUpper, isSpace)
import Data.List (dropWhileEnd)

spec :: Spec
spec = do
  describe "toNato" $ do
    it "Sample test" $ do
      toNato "If you can read" `shouldBe` "India Foxtrot Yankee Oscar Uniform Charlie Alfa November Romeo Echo Alfa Delta"
      toNato "Did not see that coming" `shouldBe` "Delta India Delta November Oscar Tango Sierra Echo Echo Tango Hotel Alfa Tango Charlie Oscar Mike India November Golf"
      toNato "go for it!" `shouldBe` "Golf Oscar Foxtrot Oscar Romeo India Tango !"

    it "Basic test" $ do
      toNato "the five boxing wizards jump quickly." `shouldBe` "Tango Hotel Echo Foxtrot India Victor Echo Bravo Oscar Xray India November Golf Whiskey India Zulu Alfa Romeo Delta Sierra Juliett Uniform Mike Papa Quebec Uniform India Charlie Kilo Lima Yankee ."
      toNato "PACK MY BOX WITH FIVE DOZEN LIQUOR JUGS?" `shouldBe` "Papa Alfa Charlie Kilo Mike Yankee Bravo Oscar Xray Whiskey India Tango Hotel Foxtrot India Victor Echo Delta Oscar Zulu Echo November Lima India Quebec Uniform Oscar Romeo Juliett Uniform Golf Sierra ?"

    it "Edge case test" $ do
      toNato "" `shouldBe` ""
      toNato "    " `shouldBe` ""
      toNato "?.!   !,!" `shouldBe` "? . ! ! , !"
      toNato "NeVeR !!!!    GoNnA   giVE  yOu uP." `shouldBe` "November Echo Victor Echo Romeo ! ! ! ! Golf Oscar November November Alfa Golf India Victor Echo Yankee Oscar Uniform Uniform Papa ."

    it "Random test" $ do
      property $ forAll (listOf $ elements (['a'..'z'] ++ ['A'..'Z'] ++ [',', '.', '!', '?'])) $ \str -> do
        toNato str `shouldBe` solution str

  where solution :: String -> String
        solution str = dropWhileEnd isSpace $ concatMap solution' str
          where solution' :: Char -> String
                solution' c
                  | isAlpha c = (nato ! toUpper c) ++ " "
                  | isSpace c = ""
                  | otherwise = c:" "
