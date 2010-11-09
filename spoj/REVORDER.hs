-- shorten-tutorial 6387
main = mapM_ putStrLn . reverse . tail . lines =<< getContents
