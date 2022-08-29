solve :: String -> [Char] -> String
solve result [] = result
solve result ('a':xs) = result ++ "a" ++ solve result (drop 2 xs)
solve result ('e':xs) = result ++ "e" ++ solve result (drop 2 xs)
solve result ('i':xs) = result ++ "i" ++ solve result (drop 2 xs)
solve result ('o':xs) = result ++ "o" ++ solve result (drop 2 xs)
solve result ('u':xs) = result ++ "u" ++ solve result (drop 2 xs)
solve result (x:xs) = result ++ [x] ++ solve result xs

main :: IO()
main = do
 line <- getLine
 let result = solve "" line
 putStrLn result 
