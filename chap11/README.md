# Chapter 11 - Arrays and Strings

Create a program that uses an array to decide what to do next.

## Guidelines
* Make an array of signed 8-bit integers (int8_t type), with at least 10 entries.
* Make a signed 8-bit integer to hold the current location, and start it at 0.
* Your program should look at the value of the integer at the current location in the array, and based on that, do something.
** For non-zero numbers, the value should be added to the current location
** For zero, the current position should be displayed, followed by a newline, and then incremented by 1.
** If the current position would be less than zero or past the end of the array, this should print out "DONE" and end the program.
* Example array with output:
<pre>
0  1  2  3  4  5  6  7  8  9 (positions)
5  0  0  5 -3  0 -2  7 -1  0 (values)
Output:
5
1
2
DONE
</pre>
* Notice that we should only see position numbers displayed that have values of 0.
* Come up with your own list of values and make sure you don't create an infinite loop.
** To halt a runaway program in linux, hit Ctrl+C
