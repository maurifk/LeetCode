module Likes where

likes :: [String] -> String
likes s = case s of
            []           -> "no one likes this"
            [s]          -> s ++ " likes this"
            [u,s]        -> u ++ " and " ++ s ++ " like this"
            [u,s,t]      -> u ++ ", " ++ s ++ " and " ++ t ++ " like this"
            u:s:xs       -> u ++ ", " ++ s ++ " and " ++ show (length xs) ++ " others like this"
