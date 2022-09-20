main :: IO()
main = do
 line <- getLine
 let [b, br, bs, a, as] = map read $ words $ line
 let minSaving = bs * (br - b)
 let (years, remain) = minSaving `divMod` as
 let ans = years + a + (if remain == 0 then 0 else 1)
 if (ans - a) * as <= minSaving
 then print (ans + 1)
 else print ans
