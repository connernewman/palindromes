#include <vector>
#include <list>
#include <iostream>

//#include "palindrome.h"

#define ABS(x) ((x) > 0 ? (x) : (-(x)))

template <typename BI>
bool _iterator_palindrome(BI& start, BI& end)
{
	if(*start != *end)
		return false;
	if(start == end || ++start == end)
		return true;
	return _iterator_palindrome(start, --end);
}

template <typename BI>
bool iterator_palindrome(BI start, BI end)
{
	if(start == end)
		return true;
	return _iterator_palindrome(start, --end);
}

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 1};
	auto vs = std::begin(v);
	auto ve = std::end(v);
	bool b = iterator_palindrome(vs, ve);
	std::cout << "v was" << (b ? "" : " not") << " a palindrome." << std::endl;

	std::list<double> l = {1.1, 2.2, 3.3, 4.4, 4.4, 3.3, 2.2, 1.1};
	auto ls = std::begin(l);
	auto le = std::end(l);
	b = iterator_palindrome(ls, le);
	std::cout << "l was" << (b ? "" : " not") << " a palindrome." << std::endl;

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

	int arr2[1000001];
	for(int i = 0; i < 1000001; ++i)
	{
		arr2[i] = ABS(500000 - i);
	}
	auto arr2s = std::begin(arr2);
	auto arr2e = std::end(arr2);
	b = iterator_palindrome(arr2s, arr2e);
	std::cout << "arr2 was" << (b ? "" : " not") << " a palindrome." << std::endl;

	std::string s = "Alpaca";
	auto ss = std::begin(s);
	auto se = std::end(s);
	b = iterator_palindrome(ss, se);
	std::cout << "s was" << (b ? "" : " not") << " a palindrome." << std::endl;
}
