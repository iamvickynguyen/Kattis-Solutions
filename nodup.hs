import Data.Set
import qualified Data.Set as Set

main :: IO()
main = do
 line <- getLine
 let wordList = words line
 let wordSet = Set.fromList wordList
 if length wordList == length wordSet
 then putStrLn "yes"
 else putStrLn "no" 
