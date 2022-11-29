solve :: Int -> String
solve n =
 if n == 1
 then show 1
 else show (n + n - 2)

main :: IO()
main = do
 contents <- getContents
 let sizes = map read $ lines contents
 let ans = map solve sizes
 putStrLn (unlines ans) 
