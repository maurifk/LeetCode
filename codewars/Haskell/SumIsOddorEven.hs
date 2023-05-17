module Kata.OddOrEven where
import Data.List( partition )



oddOrEven :: (Integral a) => [a] -> String
oddOrEven = (\(a, b) -> let limpar = length a in if odd limpar then "odd" else "even") . partition odd
