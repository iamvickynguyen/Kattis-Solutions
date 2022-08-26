fizzbuzz :: Int -> Int -> Int -> String
fizzbuzz i 0 0 = "FizzBuzz"
fizzbuzz i 0 _ = "Fizz"
fizzbuzz i _ 0 = "Buzz"
fizzbuzz i _ _ = show i

main :: IO()
main = do
 line <- getLine 
 let [x, y, n] = map read . words $ line
 let results = [fizzbuzz i modX modY
                | i <- [1..n],
                  let modX = i `mod` x,
                  let modY = i `mod` y]
 putStrLn (unlines results)
