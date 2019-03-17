.DEFAULT_GOAL := all

FILES :=			\
	.gitignore		\
	palindrome.h		\
	palindrome.c++		\
	TestPalindrome.c++

TestPalindrome:
	g++ -std=c++14 -O3 TestPalindrome.c++ -o TestPalindrome

palindrome:
	g++ -std=c++14 -O3 palindrome.c++ -o palindrome

TestPalindrome_unoptimized:
	g++ -std=c++14 -O0 TestPalindrome.c++ -o TestPalindrome_unoptimized

palindrome_unoptimized:
	g++ -std=c++14 -O0 palindrome.c++ -o palindrome_unoptimized

optimized: TestPalindrome palindrome

unoptimized: TestPalindrome_unoptimized palindrome_unoptimized

all: optimized unoptimized

clean:
	rm -f TestPalindrome
	rm -f palindrome
	rm -f TestPalindrome_unoptimized
	rm -f palindrome_unoptimized
