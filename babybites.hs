import Data.List
import Data.Maybe

main :: IO()
main = do
 contents <- getContents
 let count = words $ last $ lines contents
 let indexCount = zip [1..] count
 let result = find (\(i, saying) -> not (saying == "mumble") && not (i == (read :: String -> Int) saying)) indexCount
 if isNothing result
 then putStrLn "makes sense"
 else putStrLn "something is fishy"
