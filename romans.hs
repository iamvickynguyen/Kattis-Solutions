main :: IO()
main = do
 line <- getLine
 let x = (read :: String -> Double) line
 let answer = round (x * 1000 * 5280 / 4854)
 print answer
