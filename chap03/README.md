# Chapter 3 - Formatted Printing

Write a program that itself writes a C program that prints out the current year and welcoming text.

## Guidelines

* Create a Makefile that builds the main program, and call it "main"
* Your main.c should use printf to display the text of a C program
* In the embedded program, use an int variable named year and set it to the current 4-digit year
* Use make to compile your main program
* Run your main program and redirect the output to generated.c, like so:
<pre>./main > generated.c</pre>
* Use gcc directly to compile generated.c into a program, and call it "generated"
* Run "generated" like this:
<pre>./generated</pre>
* The output should look something like this:

<pre>
****************
* Hello, 2018! *
****************
</pre>
