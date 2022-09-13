main :: IO()
main = do
 line <- getLine
 let [h, v] = map read (words line)
 let ans = ceiling (h / sin (pi * v / 180))
 print ans
