main :: IO()
main = do
 cards <- getLine
 let (countT, countC, countG) = foldl (\ (t, c, g) i ->
                          if i == 'T'
                          then (t + 1, c, g)
                          else if i == 'C'
                          then (t, c + 1, g)
                          else (t, c, g + 1)
                        ) (0, 0, 0) cards
 let ans = countT * countT + countC * countC + countG * countG
 let bonus = min (min countT countC) countG
 print (ans + bonus * 7)
