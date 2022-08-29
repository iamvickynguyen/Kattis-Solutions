distance :: Int -> Int -> [String] -> Int
distance result prev [] = result
distance result prev [x] = result
distance result prev (x:xs) =
 distance (result + s * (t - prev)) t xs
 where [s, t] = map (read :: String -> Int) . words $ x

solve :: [String] -> String
solve [] = ""
solve [x] = ""
solve (x:xs) =
 let
  k = head $ map (read :: String -> Int) . words $ x
  inputs = take (k+1) xs
  remain = drop k xs
 in show (distance 0 0 inputs) ++ " miles\n" ++ solve remain

main :: IO()
main = do
 contents <- getContents
 let allLines = lines contents
 let results = solve allLines
 putStrLn (results)
