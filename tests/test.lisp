; Test file for Lispy Interpreter
; Run with: ./lispy tests/test.lisp

; Basic arithmetic
(print (+ 1 2 3))  ; Expected: 6

; Fibonacci sequence
(print (fib 10))   ; Expected: 55

; List operations
(print (sum {1 2 3 4}))  ; Expected: 10
(print (map (\ {x} {* x 2}) {1 2 3}))  ; Expected: {2 4 6}

; Conditional and logic
(print (if (> 5 3) {true} {false}))  ; Expected: 1 (true)

; Error case (invalid input)
; (print (fib -1))  ; Should raise an error