#include <iostream>
#include <string>
#include <string.h>
#include <vector>

#include "palindrome.h"

bool palindrome_str(std::string s)
{
	if(s.size() < 2)
		return true;
	return (s[0] == s[s.size() - 1]) && palindrome_str(s.substr(1, s.size() - 2));
}

bool palindrome_str_tr(std::string s)
{
	if(s.size() < 2)
		return true;
	if(s[0] != s[s.size() - 1])
		return false;
	return palindrome_str_tr(s.substr(1, s.size() - 2));
}

bool char_star_palindrome(char* start, char* end)
{
	if(end - start < 2)
		return true;
	return (*start == *end) && char_star_palindrome(start + 1, end - 1);
}

bool char_star_palindrome_tr(char* start, char* end)
{
	if(end - start < 2)
		return true;
	if(*start != *end)
		return false;
	return char_star_palindrome_tr(start + 1, end - 1);
}

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Provide a string:\n";
		
		std::string s;
		bool b;
		while(!std::cin.eof())
		{
			std::cin >> s;
			auto sb = s.begin();
			auto se = s.end();
			b = iterator_palindrome(sb, se);
			std::cout << s << " was " << (b ? "" : "not ") << "a palindrome.\n";
		}
	}

	else
	{
		for(int i = 1; argv[i]; ++i)
		{
			char* start = argv[i];

			// Get a pointer to the null-terminator of the string
			char* end = start + strlen(start);
			bool b = iterator_palindrome(start, end);

			std::cout << argv[i] << " was " << (b ? "" : "not ") << "a palindrome.\n";
		}
	}

	return 0;
}
