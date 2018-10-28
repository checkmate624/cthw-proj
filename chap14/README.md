# Chapter 14 - Functions

Implement the Babylonian method of square root calcluation.

## Guidelines
* Make a function that returns a double that is greater than zero and less than 1000.
* Make a function that takes two doubles and uses the Babylonian method to find its square root.
  * See explanation of the Babylonian method below
  * The first argument should be the number for which a square root should be calculated.
  * The second argument should be the desired precision.  Pass it 0.001.
  * If either argument is not greater than zero, print an error message and stop.
* The calculation function should loop until the absolute difference between the calculated square root squared and the original number is less than or equal to the precision.
* The calculation function should print out how many steps it took to reach the desired precision.

## Babylonian square root method
* In this explanation, "value" is the number for which we are calculating the square root.
* Through a series of repeated steps, we can get closer and closer to the actual square root.
* First, pick a number that is less than the value.  We'll use the value divided by 2.
* For each step, we take the average of the previous number and the value divided by the previous number.  This becomes the next number.
* Here is a worked example, using 100, and going for a precision of 0.001
  * Half of 100 is 50.  This is our starting estimate, which is obviously much too high.
  * For the next estimate, we take the average of 50 and 100/50, which is (50 + 2) / 2 = 26
  * Precision check: 26*26 = 676
    * abs(676 - 100) > 0.001
    * Not close enough, so we keep going
  * For the next estimate, we take the average of 26 and 100/26, which is (26 + 3.84) / 2 = 14.92
  * Precision check: 14.92*14.92 = 387.92
    * abs(387.92 - 100) > 0.001
    * Not close enough, so we keep going
  * For the next estimate, we take the average of 14.92 and 100/14.92, which is (14.92 + 6.70) / 2 = 10.81
  * Precision check: 10.81*10.81 = 116.86
    * abs(116.86 - 100) > 0.001
    * Not close enough, so we keep going
  * For the next estimate, we take the average of 10.81 and 100/10.81, which is (10.81 + 9.25) / 2 = 10.03
  * Precision check: 10.03*10.03 = 100.60
    * abs(100.60 - 100) > 0.001
    * Not close enough, so we keep going
  * For the next estimate, we take the average of 10.03 and 100/10.03, which is (10.03 + 9.97) / 2 = 10.00
    * All the numbers above are rounded to 2 decimal places for clarity, but the calculated result at this point would actually be 10.000046356507898
  * Precision check: 10.000046356507898 * 10.000046356507898 = 100.0000000021489
    * abs(100.0000000021489 - 100) < 0.001
    * That's close enough, so we're done!
  * In this example, the calculated result was always an overestimate (it was never lower than the true square root), but that won't be always be the case for other numbers, so you need to use the absolute value of the difference to determine if the current estimate is close enough.
