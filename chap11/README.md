# Chapter 11 - Arrays and Strings

Create a program that uses an array to decide what to do next.

## Guidelines
* Make an array of signed 8-bit integers (int8_t type), with at least 10 entries.
* Make a signed 8-bit integer to hold the current location, and start it at 0.
* Your program should consider the current position, and the integer value at that position in the array to decide what to do:
  * If the current position is less than zero or past the end of the array, print out "DONE" and end the program.
  * For non-zero values, the value should be added to the current location
  * For zero values, the current position should be displayed, followed by a newline, and then incremented by 1.
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
* Explanation:
  * At position 0, a legal position, we look at its value, which is 5.  We add 5 to the position.
  * At position 5, a legal position, we look at the value, which is 0.  We display the position (5) and add 1 to the position.
  * At position 6, a legal position, we look at the value, which is -2.  We add -2 to the position.
  * At position 4, a legal position, we look at the value, which is -3.  We add -3 to the position.
  * At position 1, a legal position, we look at the value, whcih is 0.  We display the position (1) and add 1 to the position.
  * At position 2, a legal position, we look at the value, whcih is 0.  We display the position (2) and add 1 to the position.
  * At position 3, a legal position, we look at the value, which is 5.  We add 5 to the position.
  * At position 8, a legal position, we look at the value, which is -1.  We add -1 to the position.
  * At position 7, a legal position, we look at the value, which is 7.  We add 7 to the position.
  * At position 14, an illegal position, we stop looping and display DONE.
* Notice that we should only see position numbers displayed that have values of 0.
* Come up with your own list of values and make sure you don't create an infinite loop.
  * Include at least 3 jumps and 3 displays before landing on an illegal position.
* To halt a runaway program in linux, hit Ctrl+C
