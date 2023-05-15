module Reverse where
import Data.Char ( isSpace )
import Data.List ( groupBy )

-- Spaces should be what is detected by predicate isSpace, not just ' '
reverseWords :: String -> String
reverseWords = concatMap reverse . groupBy (\x y -> x /= ' ' && y /= ' ')
