module Main where

main :: IO()
main = do
 inputNum <- getLine
 let n = read inputNum :: Int
 let d = n `mod` 4
 if d == 1 || d == 3
  then putStrLn "Alice"
  else putStrLn "Bob"
