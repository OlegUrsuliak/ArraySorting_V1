#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <chrono>
#include <stdio.h>
#include <string.h>

using namespace std;


//Заповнення масиву || Filling the array 
const int   FILLING_THE_ARRAY = 1;

//Виведення масиву || Output array
const int  SHOW_THE_ARRAY = 2;

//Знаходження мінімального і максимального елементів || Finding the minimum and maximum elements
const int  MIN_AND_MAX_ELEMENTS = 3;

//Знаходження кількості певних цифр || Finding the number of certain digits
const int  HOW_MANY = 4;

//Бульбашкове сортування || Bubble sorting
const int  BUBBLE_SORTING = 5;

//Сортування вибором || Sort by choice
const int  SELECTION_SORTING = 6;

//Швидке сортування || Quick sort
const int  QUICK_SORTING = 7;

//Сортування Шелла || Sorting Shell
const int  SORTING_SHELL = 8;

//Сортування гнома || Sort the gnome
const int  GNOME_SORTING = 9;

//Сортування odd-even ||  Sort odd-even
const int  ODD_EVEN_SORT = 10;

//Кількість букв в імені || Number of letters in the name
const int  NUMBER_OF_LETTERS_IN_THE_NAME = 0;

//Вихід || Exit
const int  Exit = 11;

const int MAX_NUMBER = 100;

//Функція заповнення масиву || Array fill function
template <typename T> void filling_the_array(const int size, T* arr, int max_number)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % max_number;
	}

}

//Функція виведення на екран масиву || Array display function
template <typename T> T show_the_array(const int size, T* arr)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	return 0;
}

//Функія знаходження максимального і мінімального елемента в масиві || Functions of finding the maximum and minimum element in an array
template <typename T> void min_max_element_of_massif(const int size, T* arr)
{
	int max = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	cout << "\nThe max element = " << max << endl;

	int min = max;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << "The min element = " << min << endl;
	cout << endl;
}

//Функція обчислення кількості цифр || Function for calculating the number of digits
template <typename T> void handle_how_many_numvber(const int size, T* arr, int number, int many)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == number)
			many++;
	}
	cout << "Number " << number << " in your array of " << many << endl;

}

template <typename T> void how_many_number(T* arr, const int size)
{
	T many = 0; //Кількість цифр

	//Введення числа
	int number = 0;
	cout << "Enter your number " << endl;
	cin >> number;

	handle_how_many_numvber(size, arr, number, many);
	cout << endl;
}

//Функція бульбашкового сортування ||Bubble sorting function
template <typename T> void  bubble_sorting(const int size, T* arr)
{
	T x = 0;

	auto start = chrono::high_resolution_clock::now();

	for (int i = 0; i < size; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;

	cout << endl;

	show_the_array(size, arr);

	cout << "\n\nSort time = " << duration.count() << "s\n" << endl;

}

//Функція сортування вибором || Selection sort function
template <typename T>void selection_sorting(const int size, T* arr)
{
	T x = 0;

	auto start = chrono::high_resolution_clock::now();

	for (size_t i = 0; i < size; i++)
	{
		int min = 0;
		min = i;
		x = arr[i];
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[j] < x)
			{
				min = j;
				x = arr[j];
			}
		}
		arr[min] = arr[i];
		arr[i] = x;
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	
	cout << endl;
	show_the_array(size, arr);
	cout << "\n" <<endl;

	cout << "\nSort time " << duration.count() << "s\n" << endl;


}

//Функція швидке сортування || Quick sort function
template <typename T>void  quick_sorting(T* arr, const int size)
{

	int i = 0, j = size;
	int temp, p;
	p = arr[size / 2];

	do
	{
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) quick_sorting(arr, j);
	if (size > i) quick_sorting(arr + i, size - i);


}

//Функція таймер швидкого сортування || Quick sort timer function
template <typename T> T time_quick_sorting(T* arr, const int size)
{
	auto start = chrono::high_resolution_clock::now();

	quick_sorting(arr, size - 1);

	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = finish - start;

	cout << endl;

	show_the_array(size, arr);

	cout << "\n\nSort time " << duration.count() << "s\n" << endl;

	return 0;
}

//Функція сортування Шелла || Sorting Shell function
template <typename T> T sorting_shell(T* arr, const int size)
{
	auto start = chrono::high_resolution_clock::now();


	for (int d = size / 2; d >= 1; d /= 2)
	{
		for (int i = d; i < size; i++)
		{
			for (int j = i; j >= d && arr[j - d] > arr[j]; j -= d)
			{
				swap(arr[j], arr[j - d]);
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;

	cout << endl;

	show_the_array(size, arr);

	cout << "\n\nSort time " << duration.count() << "s\n" << endl;

	return 0;

}

//Функція сортування гнома || Sort the gnome function
template <typename T> T gnome_sorting(T* arr, const int size)
{
	T index = 0;

	auto start = chrono::high_resolution_clock::now();

	while (index < size)
	{
		if (index == 0)
			index++;

		if (arr[index] >= arr[index - 1])
			index++;

		else {

			swap(arr[index], arr[index - 1]);
			index--;
		}
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;

	cout << endl;

	show_the_array(size, arr);

	cout << "\n\nSort time " << duration.count() << "s\n" << endl;

	return 0;
}

//Функція сортування Odd-even sort || Sort Odd-even function
template <typename T> T odd_Even_sort(T* arr, const int size)
{
	auto start = chrono::high_resolution_clock::now();

	for (int i = 0; i < size; i++)
	{
		if (i & 1)
		{
			for (int j = 2; j < size; j += 2)
			{
				if (arr[j] < arr[j - 1])
					swap(arr[j - 1], arr[j]);
			}
		}
		else
		{
			for (int j = 1; j < size; j += 2)
			{
				if (arr[j] < arr[j - 1])
					swap(arr[j - 1], arr[j]);
			}
		}
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;

	cout << endl;

	show_the_array(size, arr);

	cout << "\n\nSort time " << duration.count() << "s\n" << endl;


	return 0;
}

//Функція обчислення кількості букв в імені || The function of calculating the number of letters in the name
template <typename T>void the_number_of_digits_in_the_name(const T size)
{

	const T MAXLEN = 256;
	cout << "\nHello my name is anchovy, and what is your name " << endl;

	char string[MAXLEN];

	cout << "Input your name: ";
	cin >> string;

	cout << "\nWow, you have a beautiful name: " << endl;
	cout << "And in your name there are " << strlen(string) << " letters\n" << endl;

}

//Перевірка сортування || Sort check
template <typename T>void  audit(const int max_number, T* arr, const int size)
{
	for (T i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1] || arr[i] >= MAX_NUMBER)
			cout << "\nThe " << i << " element in array is not sorted correctly " << endl;
	}

}

int main()
{
	const int size = 1000;
	int arr[size];
	srand(time(NULL));


	bool finished = false;
	while (not finished)
	{
		//Вигляд меню || Menu view
		cout << "       Menu: " << endl;
		cout << "0.  Name " << endl;
		cout << "1.  Filling the array " << endl;
		cout << "2.  Show the array    " << endl;
		cout << "3.  Min and max elements " << endl;
		cout << "4.  How many numbers " << endl;
		cout << "5.  Buble sorting  " << endl;
		cout << "6.  Selection sort " << endl;
		cout << "7.  Quick sorting " << endl;
		cout << "8.  Sorting Shell " << endl;
		cout << "9.  Gnome sorting " << endl;
		cout << "10. Odd-even sorting " << endl;
		cout << "11. EXIT " << endl;


		//Введення пункту меню || Enter a menu item
		int choice = 0;
		cout << "Enter your choice " << endl;
		cin >> choice;

		//Границі вибору || Limits of choice
		if (choice > 11 || choice < 0)
		{
			cout << "\nI don't know what you want\n" << endl;
			continue;

		}

		//Виклик функції заповнення масиву || Call the array fill function
		if (choice == FILLING_THE_ARRAY)
		{
			filling_the_array(size, arr, MAX_NUMBER);
			cout << "\nYour array is full\n " << endl;
		}

		int print_from_intdex = -1;

		//Виклик функції виведення на екран хаотичного масиву || Call the display function of a chaotic array
		if (choice == SHOW_THE_ARRAY)
		{
			show_the_array(size, arr);
			cout << "\n" << endl;
		}

		//Виклик функції знаходження мінімального і максимального елементів || Call the function of finding the minimum and maximum elements
		if (choice == MIN_AND_MAX_ELEMENTS)
			min_max_element_of_massif(size, arr);

		//Виклик функції яка рахує кількість цифр || Call a function that counts the number of digits

		if (choice == HOW_MANY)
		{
			cout << endl;
			how_many_number(arr, size);
		}

		//Виклик функції бульбашкового сортування || Call the bubble sort function
		if (choice == BUBBLE_SORTING)
		{
			bubble_sorting(size, arr);
			cout << endl;
			audit(MAX_NUMBER, arr, size);
		}

		//Виклик функції сортування вибором || Call the sort sort function
		if (choice == SELECTION_SORTING)
		{
			selection_sorting(size, arr);
			cout << endl;
			audit(MAX_NUMBER, arr, size);
		}

		//Виклик швидкого сортування || Call quick sort
		if (choice == QUICK_SORTING)
		{
			time_quick_sorting(arr, size);
			audit(MAX_NUMBER, arr, size);
		}

		//Виклик функції сортування Шелла || Call the Shell sort function
		if (choice == SORTING_SHELL)
		{
			sorting_shell(arr, size);
			audit(MAX_NUMBER, arr, size);
		}

		//Виклик функції сортування гнома ||Call the gnome sort function
		if (choice == GNOME_SORTING)
		{
			gnome_sorting(arr, size);
			audit(MAX_NUMBER, arr, size);
		}

		//Виклик функції сортування "Odd-even sort" || Call the "Odd-even sort" function
		if (choice == ODD_EVEN_SORT)
		{
			odd_Even_sort(arr, size);
			audit(MAX_NUMBER, arr, size);
		}

		//Виклик функції обчислення кількості букв в імені || Call the function to calculate the number of letters in the name
		if (choice == NUMBER_OF_LETTERS_IN_THE_NAME)
			the_number_of_digits_in_the_name(size);

		//Виклик закінчення роботи || Call to end work
		if (choice == Exit)
			finished = true;
	}
}