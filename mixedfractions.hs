solve :: [Int] -> String
solve [0, 0] = ""
solve [a, b] = show x ++ " " ++ show y ++ " / " ++ show b
               where (x, y) = a `divMod` b

main :: IO()
main = do
 allLines <- getContents
 let tests = map (map (read :: String -> Int) . words) $ lines allLines
 let results = map solve tests
 putStrLn (unlines (filter (not . null) results))
