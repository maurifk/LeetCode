module Main (main) where

import qualified Data.Set as Set
import Data.List ( genericLength )
import Control.Monad ( replicateM )

solve :: String -> Integer
solve s = genericLength . Set.toList . Set.fromList . tail $ zipWith (\ a b -> a : [b]) ("a" ++ s) s

main :: IO ()
main = do
  t <- readLn
  testCases <- replicateM t getTestCase
  mapM_ (print . solve) testCases

getTestCase :: IO String
getTestCase = do
  _ <- getLine
  getLine
