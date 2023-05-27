module Main (main) where

import Control.Monad ( replicateM )

solve :: String -> Integer
solve = read

main :: IO ()
main = do
  t <- readLn
  testCases <- replicateM t getTestCase
  mapM_ (print . solve) testCases

getTestCase :: IO String
getTestCase = do
  _ <- getLine
  getLine
