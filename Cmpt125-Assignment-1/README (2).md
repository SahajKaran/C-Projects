## Reading Code (Quicksort)

Take a look at the code in [quicksort_messy.c](quicksort_messy.c). It's a
variation of quicksort taken from the web. Testing shows that it works
correctly, but the source code has some problems: it's not as readable as it
could be, and the coding style decisions could be improved in some places.

1. (5 marks) In a new file named `quicksort_read.c`, create a function called
   `test_quicksort_messy()` that automatically tests `quicksort_messy`. You
   can use `assert`, or any other code you need, and it should have at least 5
   different test cases.

   **Important**: Don't modify the `quicksort_messy` function --- just
   test it!

2. (10 marks) One problem with `quicksort_messy` is that the passed-in array
   `number` must be size 5. It would be much better if it could sort an array
   of any length. So to fix this, we could change the type of `number` to
   `int*`.

   Make a list of at least 5 more other source code readability or style
   problems. For each problem, describe how to fix it. Use full sentences with
   proper spelling, punctuation, and grammar.

   Put your answer into a text file named `question2.txt`.

3. (5 marks) Create a new version of `quicksort_messy` called
   `quicksort_improved` that fixes all the problems from part b). It should
   work with an array of any length (not just 5). Include a test function
   named `test_quicksort_improved` that tests it to ensure it works correctly.


## What to Submit

Put all your code into a file named `quicksort_read.c`. It should have a
`main()` function that calls both `test_quicksort_messy` and
`test_quicksort_improved`. Make sure it can be compiled on Linux using gcc and
the course makefile.

For the list in question 2, please put in comments into a text file named
`question2.txt`.

When you are ready, compress your `quicksort_read.c` and `question2.txt` files
into a zip archive named submit `assignment1.zip`. Then submit
`assignment1.zip` on Canvas.


## Hint

You **don't** necessarily need to understand the details of how the quicksort
algorithm works in order to do this assignment. All the problems in the code
are basic style and readability issues that are not specific to quicksort.
