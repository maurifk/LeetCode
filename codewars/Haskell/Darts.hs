module Codewars.Dartboard.Detection where

data DartScore
        = MissDS
        | SingleDS Int
        | DoubleDS Int
        | TripleDS Int
        | SingleBullDS
        | DoubleBullDS
        deriving (Eq, Show)

getArea :: Double -> Double -> String
getArea x y = snd $ head $ dropWhile (\(a,s) -> dist > a) [(12.7/2,"DB"), (31.8/2,"SB"),(198/2,"S"),(214/2,"T"),(324/2,"S"),(340/2,"D"),(1000000000, "X")]
            where dist = sqrt (x^2 + y^2)

ajustarCuadrante :: Double -> Double -> Double
ajustarCuadrante x y
                | x<0 && y<0 = 180
                | x<0        = 180
                | y<0        = 360
                | otherwise  = 0

getSector :: Double -> Double -> Int
getSector x y = snd $ head $ dropWhile (\(a, s) -> ang > a) $ zip [9,27..369] [6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10,6]
              where ang = (atan (y/x) * (180 / pi)) + ajustarCuadrante x y


-- | Detect a dart score with the coordinates of the hit.
getDartScore :: Double -> Double -> DartScore
getDartScore x y = case disc of
                    "DB" -> DoubleBullDS
                    "SB" -> SingleBullDS
                    "S"  -> SingleDS sect
                    "T"  -> TripleDS sect
                    "D"  -> DoubleDS sect
                    "X"  -> MissDS
                where sect = getSector x y
                      disc = getArea x y
