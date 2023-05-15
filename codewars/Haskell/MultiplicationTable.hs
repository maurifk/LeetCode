arregloMult :: Int -> Int -> [[Int]]
arregloMult tam n
                | n <= tam = map (n *) [1..tam] : arregloMult tam (n+1)
                | otherwise = []

multiplicationTable :: Int -> [[Int]]
multiplicationTable 0 = []
multiplicationTable n = [1..n] : arregloMult n 2
