module Codewars.Kata.FakeBinary where

fakeBin :: String -> String
fakeBin = map (\x -> if x<'5' then '0' else '1')
