module Codewars.SumOddNumbers where

--Should work, timeouts
{-
rowSumOddNumbers :: Integer -> Integer
rowSumOddNumbers r = sum (filter (\x -> x `mod` 2 == 1) (take (2*fromIntegral r) (drop (sum (map (2*) [1..(fromIntegral r - 1)])) [1..])))
-}
rowSumOddNumbers :: Integer -> Integer
rowSumOddNumbers r = r ^ 3
