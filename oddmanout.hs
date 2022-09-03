import Data.Bits

getString :: (Int, Int) -> String
getString (a, b) = "Case #" ++ show a ++ ": " ++ show b

solve :: [Int] -> Int
solve guests = foldl xor 0 guests

process :: [String] -> [[Int]]
process [] = []
process (x:xs) =
 intList : process (drop 1 xs)
 where intList = map (read :: String -> Int) . words $ head xs

main :: IO()
main = do
 contents <- getContents
 let allLines = drop 1 $ lines contents
 let tests = process allLines
 let results = map solve tests
 let indexResults = zip [1..] results
 let stringResults = map getString indexResults
 putStrLn (unlines stringResults)
