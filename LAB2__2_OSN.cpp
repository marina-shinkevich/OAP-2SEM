#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");

	//открываем файл для чтения
	FILE* f = fopen("f.txt", "r");
	FILE* g = fopen("g.txt", "w+");

	//проверка, что файл открылся
	if (f != NULL && g != NULL)
	{
		int number;
		while (!feof(f))
		{
			if (fscanf(f, "%d", &number) != 0)
			{
				int temp;
				int flag = 1;
				rewind(g);
				while (!feof(g))
				{
					if (fscanf(g, "%d", &temp) != 0)
					{
						if (temp == number)
						{
							flag = 0;

						}
					}
					else
					{
						break;
					}
				}
				if (flag == 1)
				{
					fprintf(g, "%d ", number);
				}
			}
			else
			{
				break;
			}
		}
		fclose(f);
		fclose(g);

	}
	else
	{
		cout << "Ошибка при открытии файлов" << endl;
	}
}