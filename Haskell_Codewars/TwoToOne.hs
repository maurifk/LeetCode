module Codewars.G964.Longest where
import qualified Data.Set as Set


longest :: [Char] -> [Char] -> [Char]
longest s1 s2 = Set.toList . Set.fromList $ (s1 ++ s2)
