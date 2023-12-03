module Disemvowel where
import Data.Char ( toLower )

disemvowel :: String -> String
disemvowel = foldl f []
                where f acc c = if esVocal c then acc else acc ++ [c]

esVocal :: Char -> Bool
esVocal c = d `elem` ['a', 'e', 'i', 'o', 'u']
        where d = toLower c