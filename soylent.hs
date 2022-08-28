soylent :: Int -> String
soylent x =
 if m == 0
  then show d
 else
  show (d + 1)
 where (d, m) = x `divMod` 400

main :: IO()
main = do
 allLines <- getContents
 let tests = map (read :: String -> Int) $ drop 1 $ lines allLines
 let results = map soylent tests
 putStrLn (unlines results)
