# Chapter 17 - Debugging memory issues

Your friend has written a program that creates and prints out 2 address structures.
It compiles!  You even see some new things in his code:
* typedef used in the definition of a structure means you don't have to say "struct" when you declare a variable of that type
* He uses some functions that may be new to you.
  * memset
  * strncpy
  * You can google these or in a linux shell type `man memset` or `man strncpy`

But you notice a few strange problems when you run it for the first time:

* For the summer home output:
  * It shows for line 1 what should have been line 2
  * It shows (null) for line 2
* It crashes before anything for the winter home is even started
  * The output says something like "free(): invalid pointer"

That sounds a lot like your friend is doing bad things with memory, so you crack out your new best friend, Valgrind.
Valgrind helps you to identify all kinds of issues, such as:
* Calling free() on memory that was not allocated on the heap
* Reading memory **after** it has been free()'d
* Failing to free() heap-allocated memory before the program exits

To get Valgrind to identify all of these terrible things, you run it like so:

`valgrind --leak-check=full ./memissues > /dev/null`

What this does, instead of running your program directly, is to run valgrind, and tell it to run your program for you.  The redirect `> /dev/null` sends stdout to a black hole so you don't see your program's output mixed in with Valgrind's results.

So, your assignment is to fix all of the issues with your friend's program.  You want Valgrind to report a clean bill of health, with no memory access or free errors, and no leaked ("lost") memory reported.  Don't be overwhelmed by the number of errors - Valgrind reports whenever something bad happens, even if is caused by the exact same code.  So if you fix one problem in code, multiple Valgrind errors may be resolved.  If you work from the top down, understanding and fixing one error at a time, you can get through them all.

## Guidelines

## Grading

The grading scale is a bit different for this assignment:

* 30 points: compiles and attempts to solve the problems
* 30 points: no memory leaks
* 30 points: no memory errors
* 20 points: comments identifying and describing fixes
