#include <vector>
#include <iostream>
#include <string>


int main()
{
	int n, a;

	std::vector<char> first;
	std::vector<char> second;

	int mass[9] = { 1,2,3,4,5,6,7,8,9 };

	std::string f;
	std::string s;
	std::cin >> f;
	//std::cin >> s;

	for (int i = 0; i < f.size(); i++)
		first.push_back(f[i]);

	//for (int i = 0; i < s.size(); i++)
		//first.push_back(s[i]);

	for (int i = 0; i < first.size(); i++)
	{
		if ((first[i] != '{') || (first[i] != '}') || (first[i] != '(') || (first[i] != ')') || (first[i] != '[') || (first[i] != ']'))
		{
			int n = 0;
			std::cout << 1 << n << "\n";
			while (n<first[i])
			{
				//first.insert(first.begin() + i, first[i - 1]);
				n++;
			}
			first.erase(first.begin() + i);
			n = 0;
		}


	}

	for (int i = 0; i < first.size(); i++)
		std::cout << first[i];

}
