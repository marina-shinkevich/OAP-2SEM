#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;


void compr(string& str)
{
	int i = 0;
	while (i < str.length())
	{
		if (str[i] == ' ')
		{
			str = str.erase(i, 1);
		}
		else
		{
			i++;
		}
	}
}



void res(string* str, ...)
{

	string** p = &str;


	int i = 0;
	while (*p != NULL)
	{
		compr((**p));
		cout << **(p) << endl;
		i++;
		p++;
	}
	string s1 = "df gd fg ";
}

int main(int argc, char* argv[])
{

	string s1 = "df gd fg ";
	string s2 = "df gd dfgdfg gdfg5434fg ";
	string s3 = "df g ds gdf gg d d fg ";
	
	res(&s1, &s2, &s3);


	string s4 = "dfgd fg ";
	string s5 = "df gd    dfgdfg gdfg5434fg ";
	string s6 = "df g n    ds gdf gg d d fg ";
	res(&s4, &s5, &s6);


	return 0;
}