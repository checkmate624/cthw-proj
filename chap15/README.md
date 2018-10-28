# Chapter 15 - Pointers

Create and use a function that takes an integer pointer, displays the pointer address, and its contents.

## Guidelines
* Your main function should declare these variables, in this order:
  * A single int variable.  Give it a value of 10.
  * An array of three integers: 1,2,3.
  * Another int variable, with a value of 20.
* Your main function should pass the address of these variables to print_address_and_value, in this order:
  * The first int variable (value 10)
  * Each of the three ints in your array
  * The last int variable (value 20)
* Your print_address_and_value function should take an integer pointer as an argument.
  * It should use printf to display the address (in hex, using %p) and value inside brackets (using %d).
* Expected output would be something like this (although the actual addresses will be different):
<pre>
0x7fff2a0330dc:10
0x7fff2a0330d0:1
0x7fff2a0330d4:2
0x7fff2a0330d8:3
0x7fff2a0330cc:20
</pre>
* Extra credit idea - compare the 4 different addresses and write a code comment with a theory about:
  * How many bytes an int takes up
  * How C organizes variables in memory when you declare them in a function
