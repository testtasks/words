import Data.List (genericTake, genericDrop)

-- alphabet = ['a'..'z']
alphabet = ['a'..'b']

m :: Integer
m = fromIntegral $ length alphabet

-- word length
n = 4

-- extends given list of words by prepending one char from alphabet to each word
-- could be applied many times iteratively
-- ex.:
--  alphabet = "abc"
--  [""] -> ["a", "b", "c"]
--  ["a", "b", "c"] -> ["aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc"]
fetchNewChar :: [String] -> [String]
fetchNewChar = concatMap $ \s -> map (\c -> c:s) alphabet

toTake = m^n
toDrop = sum $ map (\n -> m^n) [0..(n-1)]

-- result should contain words with length n
-- so we drop first A(m,0) + A(m,1) + ... + A(m,n-1) words
-- and then take first A(m,n) words
lexicographicalWords :: [String]
lexicographicalWords =
 genericTake toTake
 $ genericDrop toDrop
 $ map reverse
 $ concat
 $ iterate fetchNewChar [""]

main = do
 mapM_ putStrLn lexicographicalWords
