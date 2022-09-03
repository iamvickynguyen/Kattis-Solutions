import qualified Data.HashSet as HashSet
import Data.Char

checkExist :: String -> String
checkExist input =
 foldr (\c ans -> if (HashSet.member c uniqueChars)
                  then ans
                  else c : ans
 ) "" ['a'..'z']
 where uniqueChars = HashSet.fromList (map toLower input)


solve :: String -> String
solve input =
 if result == ""
 then "pangram"
 else "missing " ++ result
 where result = checkExist input

main :: IO()
main = do
 contents <- getContents
 let allTests = drop 1 $ lines contents
 let results = map solve allTests
 putStrLn (unlines results)
