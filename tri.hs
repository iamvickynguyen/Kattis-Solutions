main :: IO()
main = do
 line <- getLine
 let [a, b, c] = map (read :: String -> Int) . words $ line
 if a + b == c
  then putStrLn (show a ++ "+" ++ show b ++ "=" ++ show c)
 else if a - b == c
  then putStrLn (show a ++ "-" ++ show b ++ "=" ++ show c)
 else if a * b == c
  then putStrLn (show a ++ "*" ++ show b ++ "=" ++ show c)
 else if a `mod` b == 0 && snd (a `divMod` b) == c
  then putStrLn (show a ++ "/" ++ show b ++ "=" ++ show c)
 else if c + b == a
  then putStrLn (show a ++ "=" ++ show b ++ "+" ++ show c)
 else if b - c == a
  then putStrLn (show a ++ "=" ++ show b ++ "-" ++ show c)
 else if c * b == a
  then putStrLn (show a ++ "=" ++ show b ++ "*" ++ show c)
 else
  putStrLn (show a ++ "=" ++ show b ++ "/" ++ show c)
