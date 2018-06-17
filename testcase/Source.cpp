#include <stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

void strrev1(char *p1)
{
	char *pr = p1;
	for (; *pr != '\0'; pr++);
		pr--;

	for (; p1 < pr; p1++, pr--)
	{
		const char temp = *p1;
		*p1 = *pr;
		*pr = temp;
	}
}
int main()
{
	char str[]  = "abcdefg";
	char * pos = str;
	strrev1(str);
	cout << str<<endl;
	while (!_kbhit());
	
	return 0;
}