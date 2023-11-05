#include <iostream>
#include <stdexcept>
#include <string>
#include <chrono>
#include <type_traits>

using namespace std;
using namespace chrono;

template <typename T>
class DynamicArray
{
public:
	T* array;
	size_t ArraySize;
	size_t ArrayCapacity;
	
	//Konstruktor
	DynamicArray() 
	{
		ArraySize = 0;
		ArrayCapacity = 1;
		array = new T[ArrayCapacity];
	}

	//Funkcja pomocnicza
	void ExpandArray()
	{
		ArrayCapacity = ArrayCapacity * 2;
		T* expandedArray = new T[ArrayCapacity];
		for (int i = 0; i < ArraySize; i++)
			{
			expandedArray[i] = array[i];
			}
		delete[] array;
		array = expandedArray;
	}

	//a)  dodanie nowego elementu na końcu tablicy (argument: dane)
	void AddAtArrayEnd(T data)
	{
		if (ArraySize >= ArrayCapacity)
		{
			ExpandArray();
			array[ArraySize] = data;
			ArraySize++;
		}
		else
		{
			array[ArraySize] = data;
			ArraySize++;
		}
	}

	//b) zwrócenie danych i-tego elementu tablicy (argument: indeks i żądanego elementu (numerując od zera); 
	// wynik: dane i - tego elementu lub niepowodzenie w razie indeksu poza zakresem
	T& getDataUsingIndex(int index) //size_t index
	{
		if (index < 0 || index >= ArraySize) {
			throw out_of_range("Index out of range");
		}
		else {
			return array[index];
		}
	}
	
	//c) ustawienie (podmiana) danych i-tego elementu tablicy (argument: indeks i żądanego elementu
	// (numerując od zera) oraz nowe dane; wynik: pusty lub niepowodzenie w razie indeksu poza zakresem)
	void setDataUsingIndex(int index, const T& newData) //size_t index
	{
		if (index < 0 || index >= ArraySize) {
			throw out_of_range("Index out of range");
		}
		else {
			array[index] = newData;
		}
	}

	//d) czyszczenie tablicy tj. usunięcie wszystkich elementów
	void clearWholeArray() 
	{
		delete[] array;
		ArraySize = 0;
		ArrayCapacity = 1;
	}

	//e) zwrócenie napisowej reprezentacji tablicy
		string toString()
		{
			string result = "Rozmiar tablicy: " + to_string(ArraySize) + "\n";
			result += "Maksymalny rozmiar tablicy: " + to_string(ArrayCapacity) + "\n\n";
			for (int i = 0; i < ArraySize; i++)
			{
				if constexpr (std::is_convertible<T, string>::value)
				{
					result += array[i] + " ";
				}
				else
				{
					result += to_string(array[i]) + " ";
				}
			}
			return result;
		}

	//Funkcja pomocnicza
	string generateRandomString(int length) {
		string result;
		for (int i = 0; i < length; i++) {
			char randomChar = 'a' + rand() % 26;
			result += randomChar;
		}
		return result;
	}
};

int main()
{
	srand(2137);
    const int MAX_ORDER = 3;
    const int n = pow(10, MAX_ORDER); // rozmiar danych
    DynamicArray<string> dynamicArray;
    auto max_time_per_element = duration<double>::zero();
    int max_time_index = -1;

    auto t1 = high_resolution_clock::now();

    for (int i = 0; i <= n; i++)
    {
        // Pomiar czasu dodawania danych
        auto t1 = high_resolution_clock::now();
        string randomData = dynamicArray.generateRandomString(3);
        dynamicArray.AddAtArrayEnd(randomData);
        auto t2 = high_resolution_clock::now();
        auto time_per_element = duration_cast<duration<double>>(t2 - t1);

        if (time_per_element > max_time_per_element)
        {
            max_time_per_element = time_per_element;
            max_time_index = i;
        }
    }

    auto t2 = high_resolution_clock::now();
    auto totalduration = duration_cast<duration<double>>(t2 - t1);

    cout << dynamicArray.toString();
    cout << "\n\nMaksymalny czas na dodanie pojedynczego elementu: " << max_time_per_element.count() << " s (indeks " << max_time_index << ")" << endl;
    cout << "Czas calkowity: " << totalduration.count() << " sekund(y)" << endl;

    // Czyszczenie listy
    dynamicArray.clearWholeArray();

    return 0;
}