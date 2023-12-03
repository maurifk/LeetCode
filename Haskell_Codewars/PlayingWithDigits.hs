module PlayingWithDigits where
import Data.Char ( digitToInt )

digpow :: Integer -> Integer -> Integer
digpow n p = multiplo n . sum $ zipWith (^) (digs n) [p..]

digpow' :: Integer -> Integer -> Integer
digpow' n p = multiplo n . fromIntegral . sum $ zipWith (^) (map digitToInt $ show n) [p..]

multiplo :: Integer -> Integer -> Integer
multiplo n m
              | (m `mod` n) == 0 = m `div` n
              | otherwise        = -1

digs :: Integer -> [Integer]
digs 0 = []
digs n = digs (n `div` 10) ++ [n `mod` 10]