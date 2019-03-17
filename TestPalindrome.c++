#include <vector>
#include <list>
#include <iostream>

#include "palindrome.h"

#define ABS(x) ((x) > 0 ? (x) : (-(x)))

int main()
{
	std::string s = "Alpaca";
	auto ss = std::begin(s);
	auto se = std::end(s);
	bool b = iterator_palindrome(ss, se);
	std::cout << s << " was" << (b ? "" : " not") << " a palindrome." << std::endl;

	s = "amanaplanacanalpanama";
	ss = std::begin(s);
	se = std::end(s);
	b = iterator_palindrome(ss, se);
	std::cout << s << " was" << (b ? "" : " not") << " a palindrome." << std::endl;

	s = "ablewasiereisawelba";
	ss = std::begin(s);
	se = std::end(s);
	b = iterator_palindrome(ss, se);
	std::cout << s << " was" << (b ? "" : " not") << " a palindrome." << std::endl;

	std::vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 1};
	auto vs = std::begin(v);
	auto ve = std::end(v);
	b = iterator_palindrome<std::vector<int>::iterator>(vs, ve);
	std::cout << "std::vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 1} was" << (b ? "" : " not") << " a palindrome." << std::endl;

	std::list<double> l = {1.1, 2.2, 3.3, 4.4, 4.4, 3.3, 2.2, 1.1};
	auto ls = std::begin(l);
	auto le = std::end(l);
	b = iterator_palindrome(ls, le);
	std::cout << "std::list<double> l = {1.1, 2.2, 3.3, 4.4, 4.4, 3.3, 2.2, 1.1} was" << (b ? "" : " not") << " a palindrome." << std::endl;

	// 5 4 3 2 1 0 1 2 3 4 5
	int arr[11];
	for(int i = 0; i < 11; ++i)
	{
		arr[i] = ABS(5 - i);
	}
	auto arrs = std::begin(arr);
	auto arre = std::end(arr);
	b = iterator_palindrome(arrs, arre);
	std::cout << "arr was" << (b ? "" : " not") << " a palindrome." << std::endl;

	// Similar to the case above, but with a 1 million element array
	int arr2[1000001];
	for(int i = 0; i < 1000001; ++i)
	{
		arr2[i] = ABS(500000 - i);
	}
	auto arr2s = std::begin(arr2);
	auto arr2e = std::end(arr2);
	b = iterator_palindrome(arr2s, arr2e);
	std::cout << "arr2 was" << (b ? "" : " not") << " a palindrome." << std::endl;
}
