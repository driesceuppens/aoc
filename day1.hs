import System.IO  
import Control.Monad

main = do  
        let list = []
        handle <- openFile "input/day1.txt" ReadMode
        contents <- hGetContents handle
        let singlewords = words contents
            list = f singlewords
            -- end = tail list
            -- zipped = zip list end
            out = filter p (zip list (tail list))
        print (length out)
        hClose handle

f :: [String] -> [Int]
f = map read

p ::  Ord a => (a, a) -> Bool
p (a, b) = a < b
