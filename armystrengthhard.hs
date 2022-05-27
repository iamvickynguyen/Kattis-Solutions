-- practicing haskell: reading large inputs with ByteString
-- reference: https://byorgey.wordpress.com/2019/10/12/competitive-programming-in-haskell-reading-large-inputs-with-bytestring/

import Control.Arrow
import qualified Data.ByteString.Lazy.Char8 as C
import Data.List.Split
import Data.Maybe (fromJust)

main = C.interact $
 C.lines >>> drop 1 >>> chunksOf 4
 >>> map (drop 2 >>> map (C.words >>> map readInt) >>> solve)
 >>> C.unlines
 where
  -- readInt :: C.ByteString -> Maybe (Int, C.ByteString)
  readInt = C.readInt >>> fromJust >>> fst 

solve :: [[Int]] -> C.ByteString
solve [g, m] = case compare (maximum g) (maximum m) of
 LT -> C.pack "MechaGodzilla"
 _ -> C.pack "Godzilla"
