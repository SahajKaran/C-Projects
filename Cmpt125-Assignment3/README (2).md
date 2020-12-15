## Recursion

Consider this recurrence relation:

```math
\begin{aligned}
 S(1, a, b) &= a \\

 S(n, a, b) &= S(n-1) + b,\;\; n > 1
\end{aligned}
```

The variables $`n`$, $`a`$, and $`b`$ are all `int`s. You can assume $`n`$ is
always bigger than 0, but $`a`$ and $`b`$ can be any `int`s.

1. (5 marks) In a file named [S_function.c](S_function.c), implement the
   following C functions:

   - `int S1(int n, int a, int b)` uses recursion (and no loops) to calculate
     $`S(n, a, b)`$.

   - `int S2(int n, int a, int b)` uses one or more loops (and no recursion)
     to calculate $`S(n, a, b)`$.

   - `int S3(int n, int a, int b)` calculates $`S(n, a, b)`$ without using
     loops or recursion. It should be *much* more efficient than both `S1` and
     `S2`.

   - `S_test()` contains code that tests that `S1`, `S2`, and `S3` all return
     the same output for the same input. Use a loop to generate values of `n`
     from 1 to 100 (or more!), and for each `n` choose `a` and `b` randomly
     using the `rand()` function from `stdlib.h`. Check that `S1`, `S2`, and
     `S3` all return the same value for the same input.

     The testing should be automatic in the sense that a human does not need
     to manually check that the results are correct. Use if-statements, loops,
     `assert`, etc. to help implement this function.

     Your `main()` function should call the testing code `S_test()`. When the
     marker compiles and runs your program, it should print the results of
     your testing (i.e. messages that all tests passed)

   **Source code readability matters**: your code should be perfectly indented
   and easy to read.

   **Note**: If your program doesn't compile for some reason, or if it
   compiles but doesn't run correctly (or it crashes), then you will get 0 for
   all parts of this question.

2. (5 marks) Write one or two **English paragraphs** saying which of `S1`,
   `S2`, or `S3` you think is best. Justify your answer! Please use full
   sentences with perfect spelling, grammar, and formatting.

   Put this into a file named [question2.txt](question2.txt).


### What to Submit

When you are ready, put both [S_function.c](S_function.c) and
[question2.txt](question2.txt) into a zip file named `recursion.zip`. Then
upload `recursion.zip` to Canvas.
