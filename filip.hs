main :: IO()
main = do
 line <- getLine
 let [a, b] = map (read :: String -> Int) $ map reverse . words $ line
 if a > b
  then putStrLn (show a)
 else
  putStrLn (show b)
