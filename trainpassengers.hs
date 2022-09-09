import Data.List

data Reading = Reading {
 left :: Int,
 enter :: Int,
 wait :: Int

} deriving (Show)

data Train = Train {
 ontrain :: Int,
 valid :: Bool,
 stay :: Int
} deriving (Show)

parseReading :: String -> Reading
parseReading line = Reading left enter wait
 where [left, enter, wait] = map read $ words line

check :: [Train] -> Bool
check [train] = ontrain train == 0 && valid train && stay train == 0
check (train:trains) = valid train && check trains

verify :: Int -> [Reading] -> Bool
verify capacity stations = check train
 where train =  scanl (\ train reading ->  Train (ontrain train - left reading + enter reading) (ontrain train >= left reading && (ontrain train - left reading + enter reading) <= capacity && not ((ontrain train - left reading + enter reading) < capacity && wait reading > 0)) (wait reading)) (Train 0 True 0) stations

main :: IO()
main = do
 contents <- getContents
 let allLines = lines contents
 let capacity = read $ head $ words $ head allLines
 let stations = map parseReading (tail allLines)
 let result = verify capacity stations
 if result
 then putStrLn "possible"
 else putStrLn "impossible"
