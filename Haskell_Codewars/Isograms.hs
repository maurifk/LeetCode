module Isogram where
import Data.Function ( on )
import Data.Char ( toLower, ord )
import Data.List ( sortBy )

isIsogram :: String -> Bool
isIsogram = f . sortBy (compare `on` ord.toLower)
    where f [] = True
          f [s]  = True
          f all@(u:s:xs) = ((/=) `on` toLower) u s && isIsogram (tail all)
