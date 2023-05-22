module Codewars.Kata.Sheep where

countSheep :: [Bool] -> Int
countSheep = foldl (\acc x -> if x then acc + 1 else acc) 0
