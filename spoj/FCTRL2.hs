{- 24 -}
main = getLine >> (interact $ unlines . map (show.(\n -> product [1..n]).read) . lines)
