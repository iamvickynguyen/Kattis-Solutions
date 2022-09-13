main :: IO()
main = do
 contents <- getContents
 let allLines = map read $ lines contents
 let x = head allLines
 let megabytes = drop 2 allLines
 let remain = foldl (\acc i -> acc + x - i) 0 megabytes
 print (x + remain)
