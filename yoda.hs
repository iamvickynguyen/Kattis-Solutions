pad :: String -> String -> String -> String
pad a b padding =
 if length a > length b
 then ""
 else padding

main :: IO()
main = do
 first <- getLine
 second <- getLine
 let padding = replicate (abs (length first - length second)) '0'
 let a = pad first second padding ++ first
 let b = pad second first padding ++ second
 let pairs = [(x, y) | (x, y) <- zip a b]
 let result = foldl (\ (x, y) ans -> if (x > y)
                                      then (x : (fst ans), snd ans)
                                     else if x == y
                                      then (x : (fst ans), x : (snd ans))
                                     else (fst ans, y : (snd ans))
                    ) ("", "") pairs
 let (res1, res2) = result
 if res1 == ""
  then putStrLn "YODA"
 else putStrLn (show $ (read :: String -> Int) $ res1)
 
 if res2 == ""
  then putStrLn "YODA"
 else putStrLn (show $ (read :: String -> Int) $ res2)
