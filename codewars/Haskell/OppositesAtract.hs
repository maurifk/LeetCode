module Codewars.Kata.Opposites where
import Data.Function ( on )

inlove :: Int -> Int -> Bool
inlove = (/=) `on` even
