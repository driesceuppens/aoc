import System.IO  
import Control.Monad

main = do  
        let list = []
        handle <- openFile "input/day1.txt" ReadMode
        contents <- hGetContents handle
        let singlewords = words contents
            list = f singlewords
            -- First part
            first_part = filter p (zip list (tail list))
            -- Second part
            second_part = filter p (zip list (drop 3 list))
        print (length first_part)
        print (length second_part)
        hClose handle

f :: [String] -> [Int]
f = map read

p ::  Ord a => (a, a) -> Bool
p (a, b) = a < b
