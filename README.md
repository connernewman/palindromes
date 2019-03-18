# palindromes
### A study on recursion.

This project demonstrates a C++ template function to determine the "palindrome-ness" of any C++ STL or user defined bidirectionally iterable sequence.

The function to do so is implemented in a tail-recursive manner.

This code demonstrates the concise nature of recursive design, along with the power of tail call optimization.

Compiled with g++ and the -O2 or -O3 flags, the algorithm can determine palindrome-ness of arbitrarily long sequences- for instance, a one-million element array that would ostensibly take 500,000 stack frames to run to completion.

The same program, compiled with g++ -O0 or -O1, will work correctly on small input sequences, but will stack overflow and segfault on large inputs.

On my machine, this breakpoint is an input around 350,000 elements long (tested with std::string).

Additionally, the optimized program runs much faster than the unoptimized version. In my tests tail call optimization was in some cases 80+ times faster than the unoptimized binary.
