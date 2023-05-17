module MakeUpper (makeUpperCase) where
import Data.Char ( ord, chr, toUpper )

makeUpperCase :: String -> String
makeUpperCase = map (\c -> if c `elem` ['a'..'z'] then chr $ flip (-) 32 $ ord c else c)
