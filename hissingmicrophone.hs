main :: IO()
main = do
 s <- getLine
 let letterPairs = zip s (drop 1 s)
 if ('s', 's') `elem` letterPairs
 then putStrLn "hiss"
 else putStrLn "no hiss" 
