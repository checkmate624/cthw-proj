# Chapter 9 - While-Loop and Boolean Expressions

Display a 2D grid of random characters (space, plus, or asterisk)

## Guidelines
* Use integer variables for the number of rows and columns to display so that these could be changed later
* Set rows to 8 and columns to 12
* For each point in the grid, generate a random number.  If its last digit is:
  * 0-3: display a space ( )
  * 4-6: display a plus (+)
  * 7-9: display an asterisk (*)
* After each row, output a newline character
* The output should be different every time you run the program.  Here is an example:
<pre>
+ + +* ++ +*
***   *+* *+
*+++ *++ +* 
 +  ** +  *+
  * *++ *  *
+++ *  * + +
 *   * * +**
 + ++  *** *
</pre>
