toBrainfuck :: String -> String
toBrainfuck []     = ""
toBrainfuck (x:xs) = "[+]" ++ replicate (fromEnum x) '+' ++ "." ++ toBrainfuck xs

