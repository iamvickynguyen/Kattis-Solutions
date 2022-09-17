solve :: Int -> Int -> Int -> Int
solve bottles c total =
 if bottles < c
 then total
 else solve (canBuy + remain) c newTotal
  where (canBuy, remain) = bottles `divMod` c
        newTotal = total + canBuy

main :: IO()
main = do
 line <- getLine
 let [e, f, c] = map read $ words line
 let ans = solve (e + f) c 0
 print ans
