data Problem = Problem { total :: Int, diff :: Int }

solve :: Problem -> String
solve p =
 if add `mod` 2 /= 0 || a < 0 || b < 0
 then "impossible"
 else show a ++ " " ++ show b
 where add = total p + diff p
       sub = total p - diff p
       a = add `div` 2
       b = sub `div` 2


parseProblem :: String -> Problem
parseProblem s = Problem x y
 where [x, y] = map read $ words s

main :: IO()
main = do
 contents <- getContents
 let problems = map parseProblem $ drop 1 $ lines contents
 let results = map solve problems
 putStrLn (unlines results)
