module TwoSum ( twoSum ) where
import Data.List ( sortBy )
import Data.Function ( on )

twoSumAux :: [(Int, Int)] -> Int -> (Int, Int)
twoSumAux lis a
              | suma == a = (snd (head lis), snd (last lis))
              | suma <  a = twoSumAux (tail lis) a
              | suma >  a = twoSumAux (init lis) a
              where suma = fst (head lis) + fst (last lis)

twoSum :: [Int] -> Int -> (Int, Int)
twoSum xs = twoSumAux lista
      where lista = sortBy (compare `on` fst) $ zip xs [0..(length xs - 1)]


twoSum' :: [Int] -> Int -> (Int, Int)
twoSum' xs a = head [(fst x, fst y) | x <- lis, y <- lis, fst x < fst y, snd x + snd y == a]
         where lis = zip [0..(length xs - 1)] xs
