
{-# LANGUAGE BangPatterns #-}
{-# OPTIONS_GHC -O2 -optc-O2 #-}

import qualified Data.ByteString.Lazy.Char8 as C

main = do
    (_, ls) <- C.break (=='\n') `fmap` C.getContents
    line <- C.lines $ snd ls
    mapM_ . C.putStrLn . f . map C.words . 
    where
        addrev :: [C.ByteString] -> [C.ByteString]
        addrev [] = [] 
        addrev (x:xs) = (sum . map (read_integer.C.reverse) . C.split ' ') x C.cons' addrev xs

    -- let cases = read_integer l

read_integer :: C.ByteString -> Integer
-- foldr', strict
-- (*) returns Num, so need fromIntegral
read_integer = C.foldr' (\acc c -> acc * 10 + fromIntegral c - '0') 0

    (x:xs) <- map words . lines $ line
    --putStrLn $ addrev x
    where
        --addrev :: String -> String -> String
        addrev a b = dropWhile (=='0') . reverse . show $ (read.reverse) a + (read.reverse) b
--mapM_ (putStrLn . map (addrev.words)) (lines line)
    
