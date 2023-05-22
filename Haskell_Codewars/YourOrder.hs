module Codewars.Kata.YourOrderPlease (yourOrderPlease) where
import Data.List ( sortBy )
import Data.Function ( on )
import Data.Char (digitToInt, isDigit)

getNumber :: String -> Int
getNumber = foldl (\acc x -> if isDigit x then digitToInt x else acc) 0

yourOrderPlease :: String -> String
yourOrderPlease x = unwords $ map snd $ sortBy (compare `on` fst) $ zip (map getNumber $ words x) (words x)
