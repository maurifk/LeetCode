module HowGoodAreYou where
import Data.Function (on)
import Control.Applicative (Applicative(liftA2))

average :: [Int] -> Float
average = liftA2 ((/) `on` fromIntegral) sum length

betterThanAverage :: [Int] -> Int -> Bool
betterThanAverage xs x = fromIntegral x > average(x:xs)