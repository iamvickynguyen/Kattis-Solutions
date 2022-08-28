solve :: [Int] -> String
solve [0, 0] = ""
solve [a, b] =
 if a + b == 13
  then "Never speak again."
 else if a < b
  then "Left beehind."
 else if a > b
  then "To the convention."
 else
  "Undecided."
solve _ = ""

main :: IO()
main = do
 allLines <- getContents
 let tests = map (map (read :: String -> Int) . words) $ lines allLines
 let results = map solve tests
 putStrLn (unlines (filter (not . null) results))
