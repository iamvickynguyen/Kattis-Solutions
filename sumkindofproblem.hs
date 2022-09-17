data Problem = Problem {k :: Int, n :: Int}

parseProblem :: String -> Problem
parseProblem line = Problem id number
 where [id, number] = map read $ words line

solve :: Problem -> String
solve p = show (k p) ++ " " ++ show firstN ++ " " ++ show oddN ++ " " ++ show evenN
 where num = n p
       firstN = foldl (\sum i -> sum + i) 0 [1..num]
       oddN = foldl (\sum i -> sum + i) 0 [1,3..(num * 2)]
       evenN = foldl (\sum i -> sum + i) 0 [2,4..(num * 2)]
       
main :: IO()
main = do
 contents <- getContents
 let problems = map parseProblem $ drop 1 $ lines contents
 let ans = map solve problems
 putStrLn (unlines ans)
