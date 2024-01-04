numberOfBeams :: [String] -> Int
numberOfBeams bank
            | countAndFilterEmpty bank /= [] = sum $ zipWith (*) (countAndFilterEmpty bank) (tail $ countAndFilterEmpty bank)
            | otherwise = 0
            where countLasers = length . filter (/= '0')
                  filterEmptyRows = filter (/= 0)
                  countAndFilterEmpty = filterEmptyRows . map countLasers
