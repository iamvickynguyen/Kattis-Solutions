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
 let result = foldl (\ (res1, res2) (x, y) -> if (x > y)
                                      then (res1 ++ [x], res2)
                                     else if x == y
                                      then (res1 ++ [x], res2++ [y])
                                     else (res1, res2 ++ [y])
                    ) ("", "") pairs
 let (res1, res2) = result
 if res1 == ""
  then putStrLn "YODA"
 else putStrLn (show $ (read :: String -> Int) $ res1)
 
 if res2 == ""
  then putStrLn "YODA"
 else putStrLn (show $ (read :: String -> Int) $ res2)
