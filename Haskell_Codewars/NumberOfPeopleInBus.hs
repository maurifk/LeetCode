module Codewars.Kata.Bus where

number :: [(Int, Int)] -> Int
number = foldl (\acum (entra, sale) -> acum + entra - sale) 0
