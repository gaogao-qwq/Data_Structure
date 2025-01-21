module Codewars.Kata.IfYouCanReadThisSpec where

import Codewars.Kata.IfYouCanReadThis (toNato)

import Test.Hspec
import Test.QuickCheck

spec :: Spec
spec = do
  describe "toNato" $ do
    it "should work on the sample test" $ do
      toNato "If you can read" `shouldBe` "India Foxtrot Yankee Oscar Uniform Charlie Alfa November Romeo Echo Alfa Delta"
      toNato "Did not see that coming" `shouldBe` "Delta India Delta November Oscar Tango Sierra Echo Echo Tango Hotel Alfa Tango Charlie Oscar Mike India November Golf"
      toNato "go for it!" `shouldBe` "Golf Oscar Foxtrot Oscar Romeo India Tango !"
