flipBit :: String -> String -> String
flipBit [] bits = bits
flipBit (x:xs) bits =
 if x == '1'
 then flipBit xs (bits ++ "0")
 else flipBit xs (bits ++ "1")

getBits :: String -> Int -> String
getBits bits 0 = bits
getBits bits 1 = flipBit bits "" 

main :: IO()
main = do
 line <- getLine
 let n = read line
 file <- getLine
 output <- getLine
 let expected = getBits file (n `mod` 2)
 if output == expected
 then putStrLn "Deletion succeeded"
 else putStrLn "Deletion failed"
