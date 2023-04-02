#include <iostream>
#define n 150

int main()
{
	int mas[n];
	mas[0] = 1;
	mas[1] = 1;
	for (int i = 0; i < n-2; i++)
	{
		mas[i + 2] = mas[i] - mas[i + 1];
	}
	std::cout << mas[100] <<std::endl;
	std::cout << mas[102] + mas[101] - mas[100];
}