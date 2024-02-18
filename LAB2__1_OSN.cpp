#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;
//
//
//1. Дан файл вещественных чисел, содержащий элементы квадратной матрицы по строкам,
//причем начальный элемент файла содержит значение количества столбцов матрицы.
//Создать новый файл той же структуры, содержащий k - ый столбец исходной матрицы.


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");

	//открываем файл для чтения
	FILE* f = fopen("input.txt", "r");
	double** arr = NULL;
	int n;

	//проверка, что файл открылсяэ
	if (f != NULL)
	{
		if (fscanf(f, "%d", &n) == 1)
		{
			//выделили память для хранения указателей на массивы
			arr = new double* [n];
			//выделение памяти для каждой строки
			for (int i = 0; i < n; i++)
			{
				arr[i] = new double[n];
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (fscanf(f, "%lf", &arr[i][j]) == 0)
					{
						cout << "Ошибка при чтении массива" << endl;
						return 0;
					}
				}
			}
		}
		else
		{

			cout << "Ошибка при чтении размерности массива." << endl;
			return 0;
		}
		fclose(f);

	}
	else
	{
		cout << "Ошибка при открытии файла" << endl;
	}



	f = fopen("result.txt", "w");

	if (f != NULL)
	{
		int k;
		cout << "Введите k: ";
		cin >> k;


		fprintf(f, "%d\n", n);
		for (int i = 0; i < n; i++)
		{
			fprintf(f, "%.2lf\n", arr[i][k]);
		}
		fclose(f);
	}
	else
	{
		cout << "Ошибка при записи в файл." << endl;
	}





	return 0;
}