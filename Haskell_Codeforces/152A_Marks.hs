module Main (main) where

import Control.Monad ( replicateM )
import Data.Char ( digitToInt )
import Data.List ( transpose )

mapMaxToOne :: [Int] -> [Int]
mapMaxToOne [] = []
mapMaxToOne xs = map (\x -> if x == maximum xs then 1 else 0) xs


solve :: [String] -> Int
solve = sum . map esMejorEnAlgo . marcarDondeDestaca . matrizDeNums
  where matrizDeNums = map (map digitToInt)
        marcarDondeDestaca = transpose . map mapMaxToOne . transpose
        esMejorEnAlgo = (\b -> if b then 1 else 0) . any (/= 0)

main :: IO ()
main = do
  t:_ <- getLine
  testCases <- replicateM (digitToInt t) getLine
  print $ solve testCases
