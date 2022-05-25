import Control.Arrow

main :: IO()
main = interact $
 lines >>> drop 1 >>> map solve >>> unlines

solve :: String -> String
solve x = show (length x)
