-- classical 
main :: IO ()
main = do
    (_, newline:line) <- break (=='\n') `fmap` getContents
    mapM_ (putStrLn . addrev) . map words . lines $ line
{-where
        f :: [String] -> String
        f = toEnum (total)
        total = fromEnum a + fromEnum b-}
    where
        addrev :: [String] -> String
        addrev (a:b) = dropWhile (=='0') . reverse . show $ (read.reverse) a + (read.reverse) b
