data Event = Event
 {
  event :: String,
  count :: Int
 }

parseEvent :: String -> Event
parseEvent line = Event event numPeople
 where [event, count] = words line
       numPeople = (read :: String -> Int) count

solve :: Int -> [Event] -> Int -> Int -> Int
solve maxPeople [] curCount answer = answer
solve maxPeople (x:xs) curCount answer =
 if event x == "enter"
 then
  if people + curCount > maxPeople
  then solve maxPeople xs curCount (answer + 1)
  else solve maxPeople xs (curCount + people) answer
 else
  solve maxPeople xs (curCount - people) answer
 where people = count x

main :: IO()
main = do
 contents <- getContents
 let allLines = lines contents
 let l = read $ head $ words $ head allLines
 let events = map parseEvent (tail allLines)
 let ans = solve l events 0 0
 print ans
