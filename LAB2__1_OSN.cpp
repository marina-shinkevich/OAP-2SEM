#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;
//
//
//1. ��� ���� ������������ �����, ���������� �������� ���������� ������� �� �������,
//������ ��������� ������� ����� �������� �������� ���������� �������� �������.
//������� ����� ���� ��� �� ���������, ���������� k - �� ������� �������� �������.


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");

	//��������� ���� ��� ������
	FILE* f = fopen("input.txt", "r");
	double** arr = NULL;
	int n;

	//��������, ��� ���� ���������
	if (f != NULL)
	{
		if (fscanf(f, "%d", &n) == 1)
		{
			//�������� ������ ��� �������� ���������� �� �������
			arr = new double* [n];
			//��������� ������ ��� ������ ������
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
						cout << "������ ��� ������ �������" << endl;
						return 0;
					}
				}
			}
		}
		else
		{

			cout << "������ ��� ������ ����������� �������." << endl;
			return 0;
		}
		fclose(f);

	}
	else
	{
		cout << "������ ��� �������� �����" << endl;
	}



	f = fopen("result.txt", "w");

	if (f != NULL)
	{
		int k;
		cout << "������� k: ";
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
		cout << "������ ��� ������ � ����." << endl;
	}





	return 0;
}