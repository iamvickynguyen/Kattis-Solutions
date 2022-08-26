import Data.List

egypt :: [Int] -> String
egypt [0, 0, 0] = ""
egypt [a, b, c] =
 if a * a + b * b == c * c
  then "right"
 else
  "wrong"
egypt _ = "wrong"

main :: IO()
main = do
 inputs <- getContents
 let tests = map (sort . (map (read :: String -> Int))) $ map words $ lines inputs
 let results = map egypt tests
 putStrLn (unlines (filter (not . null) results))
