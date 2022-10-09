data Problem = Problem
 {
  x1 :: Float,
  y1 :: Float,
  x2 :: Float,
  y2 :: Float,
  p :: Float
 }

parseProblem :: String -> Problem
parseProblem s = Problem a1 b1 a2 b2 pnorm
 where [a1, b1, a2, b2, pnorm] = map read $ words s

calculate :: Problem -> String
calculate prob =
 show ((abs (x1 prob - x2 prob) ** (p prob) + abs (y1 prob - y2 prob) ** (p prob)) ** (1 / p prob))

main :: IO()
main = do
 contents <- getContents
 let tests = map parseProblem $ init $ lines contents
 let results = map calculate tests
 putStrLn (unlines results)
