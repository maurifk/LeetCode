module SquareDigit where
import Data.Char ( ord, chr )

numberToStringAux :: Int -> String
numberToStringAux 0 = "0"
numberToStringAux x = numberToString x

numberToString :: Int -> String
numberToString 0 = ""
numberToString num
    | num < 0  = "-" ++ numberToString (-num)
    | otherwise = numberToString (num `div` 10) <> [chr (ord '0' + num `mod` 10)]

squareDigit :: Int -> Int
squareDigit = read . concatMap (\x -> if x == '-' then "-" else numberToStringAux ((^2) (ord x - ord '0'))) . numberToStringAux
