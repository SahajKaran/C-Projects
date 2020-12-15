## Code Testing Challenge

In this assignment, your challenge is to create test cases for finding bugs in
functions. Some of the functions will have bugs, some might be bug-free. The
functions you need to test are:

- `sum_arr1`, `sum_arr2`, `sum_arr3`, `sum_arr4`: These are intended
  to sum the elements of an array of `int`s.

- `binary_search1` and `binary_search2`: These are intended to use binary
  search to find a given element in an array of `int`s.

- `sort1` and `sort2`: These are intended to arrange an array of `int`s into
  ascending sorted order.

The exact pre/post conditions and headers for these files are in
[testing_asn.h](testing_asn.h).

The testing is organized into three files:

- [secret_asn_functions.h](secret_asn_functions.h): This contains the
  functions you are supposed to test. When you are doing this assignment at
  home, implement the functions yourself (e.g. copied from the notes or the
  web is fine, as long as they follow the pre/post conditions and you properly
  cite where you got it from).

  When the marker marks your work, they will use a different
  [secret_asn_functions.h](secret_asn_functions.h) that has the same function
  headers, but with different implementations.

- [testing_asn.h](testing_asn.h): This contains your implementations of the
  "ok" functions, i.e. the functions that test the functions in
  [secret_asn_functions.h](secret_asn_functions.h). These "ok" functions have
  a standard name, e.g. `int sum_arr1_ok()` is the testing function for
  `sum_arr1`.

  Putting testing code into the bodies of these "ok" functions is your main
  task for this assignment. Use if-statements (or any other code you think
  will help) to call the corresponding function to see if it returns the
  correct value. The function should return true (1) if *all* tests pass, and
  false (0) if one, or more, test fail.

- [main.c](main.c): This is the "driver" program with the `main()` function.
  You don't need to change this is any way (but can if you like). Just
  call `make -B main` and run `./main` to see the results of your testing.

  When the marker marks your work, they will use their own `main.c`
  file.


## Other Requirements

- Use only standard C coding practices as discussed in the course, and only
  use code from the standard C library in [testing_asn.h](testing_asn.h). For
  your [secret_asn_functions.h](secret_asn_functions.h), you can use any code
  you like, e.g. from the notes, textbook, or web.

- Use good coding style, e.g. perfect and consistent indentation, sensible
  variable names, comments when necessary, etc. Make your code easy to read.

- Your program should not take more than **5 seconds** to run. Don't run a lot
  of pointless test cases: every test case should have a reason for being
  there.

- Your program should never crash, so don't use `assert` in your "ok"
  functions.

- It is possible that certain inputs for buggy functions could crash your
  program. If that happens, the marker will treat that test function as if it
  returned false (0), and comment it out and re-run your other code.


## What to Submit

Submit just your modified version of [testing_asn.h](testing_asn.h) on
[Canvas](https://canvas.sfu.ca/).
