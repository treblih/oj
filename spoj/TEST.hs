{- 1 -}
main = interact $ unlines . takeWhile (/= "42") . lines
