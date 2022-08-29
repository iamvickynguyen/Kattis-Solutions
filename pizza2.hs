main :: IO()
main = do
 line <- getLine
 let [r, c] = map (read :: String -> Int) . words $ line
 let numerator = fromIntegral ((r - c) * (r - c) * 100) :: Float
 let denominator = fromIntegral (r * r) :: Float
 let ans = numerator/denominator
 putStrLn (show ans)
