module Joggers where

nbrOfLaps :: Integer -> Integer -> (Integer, Integer)
nbrOfLaps bob charles = (a `div` bob, a `div` charles)
                      where a = lcm bob charles
