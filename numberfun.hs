numberfun :: Int -> Int -> Int -> Bool
numberfun a b c =
 a + b == c
 || a - b == c
 || a * b == c
 || (a `mod` b == 0 && fst (a `divMod` b) == c)

solve :: String -> String
solve test =
 if numberfun a b c || numberfun b a c
  then "Possible"
 else
  "Impossible"
 where [a, b, c] = map read . words $ test

main :: IO()
main = do
 allLines <- getContents
 let tests = drop 1 $ lines allLines
 let results = map solve tests
 putStrLn (unlines results)
