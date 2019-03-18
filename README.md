# palindromes
### A study on recursion.

This project demonstrates a C++ template function to determine the "palindrome-ness" of any C++ STL or user defined bidirectionally iterable sequence.

The function to do so is implemented in a tail-recursive manner.

This code demonstrates the concise nature of recursive design, along with the power of tail call optimization.

Compiled with g++ and the `-O2` or `-O3` flags, the algorithm can determine palindrome-ness of arbitrarily long sequences- for instance, a one-million element array that would ostensibly take 500,000 stack frames to run to completion.

The same program, compiled with `g++ -O0` or `-O1`, will work correctly on small input sequences, but will stack overflow and segfault on large inputs.

On my machine, this breakpoint is an input around 350,000 elements long (tested with std::string).

Additionally, the optimized program runs much faster than the unoptimized version. In my tests tail call optimization was in some cases *80+* times faster than the unoptimized binary.

## Usage

`make` will create 4 binaries, the palindrome program itself and a TestPalindrome program in both optimized and unoptimized versions.

The TestPalindrome program demonstrates the benefits of tail call optimization:

```
$ ./TestPalindrome
Alpaca was not a palindrome.
amanaplanacanalpanama was a palindrome.
ablewasiereisawelba was a palindrome.
std::vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 1} was a palindrome.
std::list<double> l = {1.1, 2.2, 3.3, 4.4, 4.4, 3.3, 2.2, 1.1} was a palindrome.
arr was a palindrome.
arr2 was a palindrome.
```

```
$ ./TestPalindrome_unoptimized
Alpaca was not a palindrome.
amanaplanacanalpanama was a palindrome.
ablewasiereisawelba was a palindrome.
std::vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 1} was a palindrome.
std::list<double> l = {1.1, 2.2, 3.3, 4.4, 4.4, 3.3, 2.2, 1.1} was a palindrome.
arr was a palindrome.
Segmentation fault (core dumped)
```
