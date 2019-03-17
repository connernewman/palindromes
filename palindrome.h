#ifndef palindrome_h
#define palindrome_h

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

#endif
