main :: IO()
main = do
 input <- getLine
 let [n, m] = map read . words $ input
 if n < m
  then if m - n > 1
        then putStrLn ("Dr. Chaz will have " ++ show (m - n) ++ " pieces of chicken left over!")
       else
        putStrLn ("Dr. Chaz will have " ++ show (m - n) ++ " piece of chicken left over!")
 else
  if n - m > 1
   then putStrLn ("Dr. Chaz needs " ++ show (n - m) ++ " more pieces of chicken!")
  else
   putStrLn ("Dr. Chaz needs " ++ show (n - m) ++ " more piece of chicken!")
