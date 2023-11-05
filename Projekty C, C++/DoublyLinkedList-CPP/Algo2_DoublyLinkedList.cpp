#include <iostream>
#include <string>
#include <chrono>
#include <type_traits>

using namespace std;

template <typename T>
class list_node
{
public:
    T data;
    list_node<T>* next;
    list_node<T>* prev;

    list_node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class list
{
private:
    list_node<T>* head;
    list_node<T>* tail;
    int size;

public:
    list() : head(nullptr), tail(nullptr), size(0) {}

    //(a) dodanie nowego elementu na końcu listy
    void addAtTail(T data)
    {
        list_node<T>* temp = new list_node(data);
        if (size == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    //(b) dodanie nowego elementu na początku listy
    void addAtHead(T data)
    {
        list_node<T>* temp = new list_node(data);
        if (size == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        size++;
    }

    //(c) usunięcie ostatniego elementu
    bool deleteTail()
    {
        if (size == 0)
        {
            return false;
        }
        else if (size == 1)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail->prev->next = nullptr;
            list_node<T>* temp = tail;
            tail = tail->prev;
            delete temp;
        }
        size--;
        return true;
    }

    //(d) usunięcie pierwszego elementu
    bool deleteHead()
    {
        if (size == 0)
        {
            return false;
        }
        else if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head->next->prev = nullptr;
            list_node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size--;
        return true;
    }

    //(e) zwrócenie danych i-tego elementu listy
    T getDataUsingIndex(int index)
    {
        if (index < 0 || index >= size || head == nullptr)
        {
            return T();
        }
        list_node<T>* current = head;

        if (index >= (size / 2))
        {
            for (int i = size - 1; i > index; i--)
            {
                if (current == nullptr)
                {
                    return T();
                }
                current = current->prev;
            }
            return current->data;
        }
        else
        {
            for (int j = 0; j < index; j++)
            {
                if (current == nullptr)
                {
                    return T();
                }
                current = current->next;
            }
            return current->data;
        }
    }

    //(f) ustawienie (podmiana) danych i-tego elementu listy (argumenty: indeks "i" żądanego elementu
    //(numerując od zera) oraz nowe dane; wynik: pusty lub niepowodzenie w razie indeksu poza zakresem)
    void setDataUsingIndex(int index, T newData)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        list_node<T>* current = head;

        if (index >= (size / 2))
        {
            for (int i = size - 1; i > index; i--)
            {
                current = current->prev;
            }
            current->data = newData;
        }
        else
        {
            for (int j = 0; j < index; j++)
            {
                current = current->next;
            }
            current->data = newData;
        }
    }

    //(g) wyszukanie elementu (argumenty: dane wzorcowe oraz informacja lub komparator definiujące klucz wyszukiwania
    // — szczegółowe wskazówki dalej; wynik: wskaźnik na odnaleziony element listy lub NULL w przypadku niepowodzenia)
    int searchElement(const T& targetData)
    {
        const list_node<T>* current = head;
        int index = 0;

        while (current != nullptr)
        {
            if (current->data == targetData)
            {
                return index; // Znaleziono element
            }

            current = current->next;
            index++;
        }

        return -1; // Element nie został znaleziony
    }

    //(h) wyszukanie i usunięcie elementu (argumenty: jak wyżej; wynik: flaga logiczna sygnalizująca powodzenie lub niepowodzenie)
    bool searchElementAndRemove(const T& targetData)
    {
        list_node<T>* current = head;
        while (current != nullptr)
        {
            if (current->data == targetData)
            {
                if (current == head)
                {
                    deleteHead();
                    return true;
                }
                else if (current == tail)
                {
                    deleteTail();
                    return true;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    size--;
                    return true;
                }
            }
            current = current->next;
        }
        return false;
    }
    
    //(i) dodanie nowego elementu z wymuszeniem porządku (argumenty: dane i informacja lub komparator definiujące klucz porządkowania)

    //(j) czyszczenie listy tj. usunięcie wszystkich elementów
    void clearWholeList()
    {
        /*
        while (size > 0)
        {
            deleteTail();
        }
        */
        int i = 0;
        while(i < size)
        {
            list_node<T>* temp = head;
            head = head->next;
            delete temp;
            i++;
        }
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    //(k) zwrócenie napisowej reprezentacji listy
    string listToString(int elementsToString)
    {
        string listString;
        list_node<T>* current = head;
        int k = 0;

        if (elementsToString <= 0)
        {
            return "";
        }
        else
        {
            while (k < elementsToString && current != nullptr)
            {
                if constexpr (is_same_v<T, string>) {
                    listString += current->data + ",";
                }
                else {
                    listString += to_string(current->data) + ",";
                }
                current = current->next;
                k++;
            }
            return listString;
        }
    }

    //wyswietlanie calej listy
    void showList()
    {
        if (size == 0)
        {
            return;
        }
        else
        {
            list_node<T>* temp = head;
            for (int i = 0; i < size; i++)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }

    //funkcja pomocnicza
    string generateRandomString(int length) {
        string result;
        for (int i = 0; i < length; i++) {
            char randomChar = 'a' + rand() % 26;
            result += randomChar;
        }
        return result;
    }
};

int main() {
    srand(2137);
    const int MAX_ORDER = 6;
    list<string> myList;

    for (int o = 1; o <= MAX_ORDER; o++)
    {
        const int n = pow(10, o); // rozmiar danych

        // Pomiar czasu dodawania danych
        auto t1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
        {
            string randomData = myList.generateRandomString(3);
            myList.addAtTail(randomData);
        }
        auto t2 = chrono::high_resolution_clock::now();
        auto elapsedTimeMillis = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
        auto elapsedTimeMicros = chrono::duration_cast<chrono::microseconds>(t2 - t1);
        cout << "Czas dodawania " << n << " elementow: " << elapsedTimeMillis << ", dokladniej " << elapsedTimeMicros << endl;

        //Pomiar czasu znajdowania i usuwania danych
        
        const int m = pow(10, 4); // liczba prob wyszukania
        auto t3 = chrono::high_resolution_clock::now();
        for (int i = 0; i < m; i++) {
            string randomData = myList.generateRandomString(3);
            myList.searchElementAndRemove(randomData);
        }
        auto t4 = chrono::high_resolution_clock::now();
        auto elapsedTimeMillis2 = chrono::duration_cast<chrono::milliseconds>(t4 - t3);
        auto elapsedTimeMicros2 = chrono::duration_cast<chrono::microseconds>(t4 - t3);
        cout << "Czas znajdowania i usuwania " << n << " elementow: " << elapsedTimeMillis2 << ", dokladniej " << elapsedTimeMicros2 << endl;

        //Czyszczenie listy
        myList.clearWholeList();
    }
    return 0;
}
