module TotalPoints where
import Data.Char ( ord )

separarCadaString :: String -> [Int]
separarCadaString (x:_:y:resto) = map (\x -> ord x - ord '0') (x : [y])

puntaje :: [Int] -> Int
puntaje (x:y:resto) | x > y = 3
                    | x == y = 1
                    | otherwise = 0

points :: [String] -> Int
points = sum . map (puntaje . separarCadaString)
