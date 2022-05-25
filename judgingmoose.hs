import Control.Arrow

main :: IO()
main = interact $
 lines >>> head >>> words >>> map read >>> solve

solve :: [Integer] -> String
solve [a, b]
 | a == 0 && b == 0 = "Not a moose"
 | a == b = "Even " ++ show (a * 2)
 | otherwise = "Odd " ++ show ((max a b) * 2)
