module OnesAndZeroes (toNumber) where

toNumber :: [Int] -> Int
toNumber = foldl (\acc x -> acc * 2 + x) 0
