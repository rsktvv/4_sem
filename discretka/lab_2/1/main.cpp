#include <iostream>

int main()
{
	int n = 1;
	int m = 5;
	for (int i = 10; i >= m; i--)
		n *= i;
	std::cout << n;
	return 0;
}