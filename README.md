# Debounce Tests
Arduino push-button debounce tests.

This repository contains the debounce tests discussed in the blog post http://www.jsware.io/programming/2022/10/19/Bouncing-Buttons/

* `Debounce0` shows direct LED control without debouncing.
* `Debounce1` is a toggle LED example without debouncing, showing the problem.
* `Debounce2` provides an improvement of the standard Debounce examples found in the Arduino IDE.
* `Debounce2b` provides further optimisations of Debounce2, using byte variables instead of bool.
* `Debounce3` is a bit-shifting reader using a 5ms timer in the loop() function.
* `Debounce3b` is a bit-shifting reader using a loop() function counter.

Clone the repository and open each example in the Arduino IDE. Then upload to the Arduino of your choice.
