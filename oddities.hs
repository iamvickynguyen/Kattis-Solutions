module Main where

parseTests :: [String] -> [Int]
parseTests (hd:tl) = map read tl

solve :: Int -> String
solve x =
 if (x `mod` 2) == 0
  then (show x) ++ " is even"
  else (show x) ++ " is odd"

main :: IO()
main = do
 allInput <- getContents
 let allLines = lines allInput
 let tests = parseTests allLines
 let results = map solve tests
 putStrLn (unlines results)
