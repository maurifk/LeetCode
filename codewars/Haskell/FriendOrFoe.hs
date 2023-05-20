module FriendOrFoe where
import Data.Function ( on )

friend :: [String] -> [String]
friend = filter (((==) `on` length) "nice")
