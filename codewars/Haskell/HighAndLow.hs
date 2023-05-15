module Kata (highAndLow) where
import Data.List ( sort )

cabYCola :: [Integer] -> [Integer]
cabYCola inp = head inp : [last inp]


highAndLow :: String -> String
highAndLow = unwords . map show . cabYCola . reverse . sort . map read . words
