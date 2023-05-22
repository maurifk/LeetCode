module DescendingOrder where
import Data.List ( sort )

separarPorDigitos :: Integer -> [Integer]
separarPorDigitos 0 = []
separarPorDigitos x = separarPorDigitos (x `div` 10) ++ [x `mod` 10]

juntarDigitos :: [Integer] -> Integer
juntarDigitos = foldl (\acc x -> (acc * 10) + x) 0

descendingOrder :: Integer -> Integer
descendingOrder = juntarDigitos . reverse . sort . separarPorDigitos
