import Data.List

solve :: [(Int, Int)] -> Int
solve [] = 0
solve ((a, b):xs) =
 if a == b then solve xs else b

main :: IO()
main = do
 contents <- getContents
 let allLines = lines contents
 let [r, n] = map (read :: String -> Int) . words $ head allLines
 if r == n
  then putStrLn "too late"
 else
  let bookedRooms = map (read :: String -> Int) (drop 1 allLines)
      roomWithIndex = zip [1..] (sort bookedRooms)
      room = solve roomWithIndex
  in putStrLn (show room)
