import Control.Arrow

main :: IO()
main = interact $
 lines >>> map (words >>> map read >>> solve >>> show) >>> unlines

solve :: [Integer] -> Integer
solve [a,b] = abs (a - b)
