import Data.List
import Data.Char (isSpace)

trim :: String -> String
trim = f . f
 where f = reverse . dropWhile isSpace

cmp :: String -> String -> Ordering
cmp a b
 | length a > length b = GT
 | length a == length b && a > b = GT
 | otherwise = LT

parseProblem :: [String] -> [[String]]
parseProblem [] = []
parseProblem (x:xs) = (take k xs) : parseProblem (drop k xs)
 where k = (read :: String -> Int) x

getHalf :: [String] -> Int -> [String]
getHalf [] _ = []
getHalf (x:xs) i =
 if i `mod` 2 == 0
 then x : getHalf xs (i + 1)
 else getHalf xs (i + 1)

solve :: [String] -> [String]
solve p = firstHalf ++ secondHalf
 where newList = sortBy cmp p
       firstHalf = getHalf newList 0
       oddHalf = getHalf newList 1
       secondHalf = reverse oddHalf

formatResult :: (Int, [String]) -> String
formatResult (index, results) =
 if length results == 0
 then ""
 else "SET " ++ show index ++ "\n" ++ trim (unlines results)

main :: IO()
main = do
 contents <- getContents
 let problems = parseProblem (lines contents)
 let results = zip [1..] (map solve problems)
 let answer = map formatResult results
 putStr (unlines $ filter (not . null)  answer) 
