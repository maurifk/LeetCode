import Data.Function ( on )
import Data.List ( maximumBy, group )

longestRepetition :: String -> Maybe (Char, Int)
longestRepetition "" = Nothing
longestRepetition str = Just . maximumBy (compare `on` snd) . map (\s -> (head s, length s)) . group $ reverse str
