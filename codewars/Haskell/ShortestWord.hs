module FindShortest ( findShortest ) where

findShortest :: String -> Integer
findShortest = fromIntegral . minimum . map length . words
