import Data.List

simonsays :: String -> String
simonsays s =
 if isPrefixOf "Simon says" s
  then drop (length "Simon says ") s
 else
  ""

main :: IO()
main = do
 inputs <- getContents
 let tests = drop 1 $ lines inputs
 let results = map simonsays tests
 putStrLn (unlines $ filter (not . null) results)
