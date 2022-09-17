main :: IO()
main = do
 line <- getLine
 let [n, h, v] = map read $ words line
 let height = max h (n - h)
 let width = max v (n - v)
 let volume = height * width * 4
 print volume
