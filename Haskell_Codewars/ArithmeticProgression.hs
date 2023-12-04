module Haskell_Codewars.ArithmeticProgression where
import Data.List ( groupBy, sort )

todosIgual :: (Eq a) => [a] -> Bool
todosIgual xs = all (== head xs) (tail xs)

esSecAritmetica :: [Int] -> Bool
esSecAritmetica = todosIgual . tail . (zipWith (-) <*> tail) . sort
