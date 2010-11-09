-- shorten-main 7105
{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O2 -optc-O2 #-}
main = do
    -- l holds string
    (n, l) <- break (=='\n') `fmap` getContents
    -- concat :: [[a]] -> [a]
    let (one:other) = concat . map (replicate (read n)) . words . reverse $ l
    -- "a" ++ " a" ++ " a" .. ++ '\n'
    putStr one >> mapM (\str -> putChar ' ' >> putStr str) other >> putChar '\n'
