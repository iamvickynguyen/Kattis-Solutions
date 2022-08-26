quadrant :: Bool -> Bool -> String
quadrant True True = "1"
quadrant False True = "2"
quadrant False False = "3"
quadrant _ _ = "4"

main :: IO()
main = do
 line <- getLine
 let x = read line :: Int
 line <- getLine
 let y = read line :: Int
 putStrLn (quadrant (x > 0)  (y > 0))
