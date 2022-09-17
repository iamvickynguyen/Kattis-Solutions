sumDigits :: Int -> Int -> Int
sumDigits 0 s = s
sumDigits n s = sumDigits d (s + r)
 where (d, r) = n `divMod` 10

solve :: Int -> Int
solve n =
 if n `mod` d == 0
 then n
 else solve (n + 1)
  where d = sumDigits n 0

main :: IO()
main = do
 line <- getLine
 let n = read line
 let ans = solve n
 print ans 
