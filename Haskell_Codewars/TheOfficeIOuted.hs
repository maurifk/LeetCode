module Office where

outed :: [(String,Int)] -> String -> String
outed xs s = if fromIntegral (sum (map f xs)) / fromIntegral (length xs) <= 5 then "Get Out Now!" else "Nice Work Champ!"
      where f (nom, i) = if nom == s then i*2 else i
