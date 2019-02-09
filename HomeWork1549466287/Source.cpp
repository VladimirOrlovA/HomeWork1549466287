#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void FillArrayOrder(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = i;
}

void FillArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 1 + rand() % 9;
}

void FillArray(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = float(1 + rand() % 5) / (2 + rand() % 3);
		arr[i] = float(int(arr[i] * 100) % 100) / 100;
	}
}

void FillArray(char arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 256;
}

void PrintArray(int arr[], int n)
{
	cout << endl << endl;

	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

void PrintArray(float arr[], int n)
{
	cout << endl << endl;

	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

void PrintArray(char arr[], int n)
{
	cout << endl << endl;

	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

void SearchMax(char arr[], int n, char x)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > x) count++;
	}

	cout << "Кол-во элементов больше " << x << " =>  " << count << endl << endl;
}

void ReorderingArray(int arr[], int n)
{
	int c;
	for (int i = 0; i < n / 2; i++)
	{
		c = arr[i];
		arr[i]=arr[n-i-1];
		arr[n-i-1] = c;
	}
}


void Task1()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout <<"\n--------------------------------------------------------------------------\n\nTask1\n\n";
	cout <<"1. *Напишите функцию, которая определяет количество  элементов передаваемого массива, которые больше определенного числа, это число тоже передается в функцию. Реализовать перегрузки для различных типов массивов.\n\n";
	SetConsoleTextAttribute(hConsole, 7);

		int const n = 10;
		char arr[n] = { 0 }, x = 'C';

		FillArray(arr, n);
		PrintArray(arr, n);
		SearchMax(arr, n, x);
	
}


void Task2()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout <<"\n--------------------------------------------------------------------------\n\nTask2\n\n";
	cout <<"\n//2.	**Написать функцию, которая меняет порядок элементов передаваемого массива на обратный.Внутри функции запрещено использовать вспомогательный массив.Реализовать перегрузки для различных типов массивов.\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int const n = 10;
	int arr[n] = { 0 };
		
	FillArrayOrder(arr, n);
	PrintArray(arr, n);
	ReorderingArray(arr, n);
	PrintArray(arr, n);

}



int main()
{
	cout << "\n  06_02_2019_1549466287 \n\n";
	
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number, flag;

	do
	{
		cout << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		
		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? 1/0 => ";
		cin >> flag;

	} while (flag == 1);

	
	if (flag == 1)
		system("pause");
	
}

