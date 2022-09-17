solve :: Int -> Int -> String
solve 1 result = show result
solve n result = solve (n - 1) lastDigit
 where lastDigit = (result * n) `mod` 10

main :: IO()
main = do
 contents <- getContents
 let numbers = map read $ drop 1 $ lines contents
 let ans = map (\i -> solve i 1) numbers
 putStrLn (unlines ans)
