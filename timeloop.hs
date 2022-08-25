module Main where

main :: IO()
main = do
 inputNum <- getLine
 let n = read inputNum :: Int
 let outputs = map (\i -> show i ++ " Abracadabra") [1..n]
 putStrLn (unlines outputs)
