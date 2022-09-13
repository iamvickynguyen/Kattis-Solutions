calculateTerm :: Int -> Int
calculateTerm n = foldl (\acc i -> acc * i) 1 ds
 where (d, m) = n `divMod` 10
       ds = take m $ repeat d

main :: IO()
main = do
 contents <- getContents
 let numbers = map (read :: String -> Int) $ drop 1 $ lines contents
 let answer = foldl (\acc i -> acc + calculateTerm i) 0 numbers
 print answer
