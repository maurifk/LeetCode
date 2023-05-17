module Codewars.G964.Getmiddle where

getMiddle :: String -> String
getMiddle s
            | odd $ length s = [s !! (length s `div` 2)]
            | otherwise = [s !! ((length s `div` 2)  - 1), s !! (length s `div` 2)]
