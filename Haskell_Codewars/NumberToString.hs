module Stringify where
import Data.Char ( ord, chr )

numberToString :: Int -> String
numberToString 0 = ""
numberToString num
    | num < 0  = ['-'] <> numberToString (-num)
    | otherwise = numberToString (num `div` 10) <> [chr (ord '0' + num `mod` 10)]
