{- 4073 -}
chain :: Int a => a -> [a]
chain n
    | even n = n : chain (n `div` 2)
    | otherwise n = n : chain (3 * n + 1)
