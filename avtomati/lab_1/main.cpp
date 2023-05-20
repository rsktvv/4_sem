#include <vector>
#include <iostream>
#include <string>


int main()
{

	std::vector<char> first;
	std::vector<char> second;
	std::vector<char> first_temp;
	std::vector<char> second_temp;

	std::string f;
	std::string s;
	std::cin >> f;
	std::cin >> s;

	for (int i = 0; i < f.size(); i++)
		first.push_back(f[i]);

	for (int i = 0; i < s.size(); i++)
		second.push_back(s[i]);

	for (int i = 0; i < first.size(); i++)
	{
		if ((first[i] != '{') && (first[i] != '}') && (first[i] != '(') && (first[i] != ')') && (first[i] != '[') && (first[i] != ']'))
		{
			int  p = 0;
			std::cout << 1 << "\n";
			while (p < (first[i]-'0'))
			{
				first_temp.push_back(first[i - 1]);
				p++;
			}
			p = 0;
		}
		else
		{
			first_temp.push_back(first[i]);
		}

	}

	for (int i = 0; i < second.size(); i++)
	{
		if ((second[i] != '{') && (second[i] != '}') && (second[i] != '(') && (second[i] != ')') && (second[i] != '[') && (second[i] != ']'))
		{
			int  p = 0;
			while (p < (second[i] - '0'))
			{
				second_temp.push_back(second[i - 1]);
				p++;
			}
			p = 0;
		}
		else
		{
			second_temp.push_back(second[i]);
		}

	}


	if (first_temp == second_temp)
		std::cout << "ravni";
	else
		std::cout << "ne ravni" ;

	return 0;


}
