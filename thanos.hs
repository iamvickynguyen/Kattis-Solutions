data Problem = Problem { p :: Int, r :: Int, f :: Int }

parseProblem :: String -> Problem
parseProblem line = Problem population factor food
 where [population, factor, food] = map read $ words line

count :: Int -> Int -> Int -> Int -> Int
count p r f cnt =
 if p > f
 then cnt
 else count (p * r) r f (cnt + 1)

solve :: Problem -> String
solve prob = show result
 where result = count (p prob) (r prob) (f prob) 0

main :: IO()
main = do
 contents <- getContents
 let problems = map parseProblem $ drop 1 $ lines contents
 let results = map solve problems
 putStrLn (unlines results)
