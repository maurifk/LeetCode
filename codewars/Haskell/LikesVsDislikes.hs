module LikesVsDislikes (likeOrDislike) where
data Like = Like | Dislike

likeOrDislikeAux :: Maybe Like -> [Like] -> Maybe Like
likeOrDislikeAux lik [] = lik
likeOrDislikeAux lik (h:t)
                | lik == Nothing = likeOrDislikeAux (Just h) t
                | lik /= Just h = likeOrDislikeAux (Just h) t
                | otherwise = likeOrDislikeAux Nothing t

likeOrDislike :: [Like] -> Maybe Like
likeOrDislike [] = Nothing
likeOrDislike xs = likeOrDislikeAux Nothing xs
