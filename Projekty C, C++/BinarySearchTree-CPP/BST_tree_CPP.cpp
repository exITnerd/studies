#include <iostream>
#include <list>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
public:
    TreeNode<T>* root;
    int size;
    BinarySearchTree() : root(nullptr), size(0) {}

    //a) dodanie nowego elementu do drzewa
    void AddToTree(T data) {
        TreeNode<T>* newNode = new TreeNode<T>(data);

        if (root == nullptr) {
            root = newNode;
            size = 1;
            return;
        }

        TreeNode<T>* current = root;
        while (current != nullptr) {
            if (data < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    newNode->parent = current;
                    size++;
                    return;
                }
                current = current->left;
            }
            else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    newNode->parent = current;
                    size++;
                    return;
                }
                current = current->right;
            }
        }
    }

    //b) wyszukanie elementu
    TreeNode<T>* Find(T SearchKey) {
        TreeNode<T>* current = root;

        while (current != nullptr) 
        {
            if (SearchKey == current->data) {
                return current; // Znaleziono element, zwracamy wskaźnik na niego
            }
            else if (SearchKey < current->data) {
                current = current->left; // Przesuwamy się w lewo
            }
            else {
                current = current->right; // Przesuwamy się w prawo
            }
        }
        return nullptr;
    }

    //d) przejście pre-order drzewa
    void PreOrder(TreeNode<T>* root, list<T>& result) {
        if (root != nullptr) {
            result.push_back(root->data); // Wchodzimy do korzenia
            PreOrder(root->left, result); // Przechodzimy przez lewe poddrzewo
            PreOrder(root->right, result); // Przechodzimy przez prawe poddrzewo
        }
        else {
            return;
        }
    }

    //e) przejście in-order drzewa
    void InOrder(TreeNode<T>* root, list<T>& result) {
        if (root != nullptr) {
            InOrder(root->left, result); // Przechodzimy przez lewe poddrzewo
            result.push_back(root->data); // Wchodzimy do korzenia
            InOrder(root->right, result); // Przechodzimy przez prawe poddrzewo
        }
        else {
            return;
        }
    }

    //f) czyszczenie drzewa tj. usunięcie wszystkich elementów
    void ClearTree(TreeNode<T>*& root) {
        if (root != nullptr) {
            ClearTree(root->left); // Czyścimy całe lewe drzewo
            ClearTree(root->right); // Czyścimy całe prawe drzewo
            delete root; // Usuwamy korzeń
            root = nullptr;
        }
        else {
            return;
        }
    }

    //g) wyznaczenie wysokości drzewa
    int TreeHeight(TreeNode<T>* root) {
        if (root != nullptr) {
            int leftHeight = TreeHeight(root->left);
            int rightHeight = TreeHeight(root->right);
            
            if (leftHeight >= rightHeight){
                return leftHeight + 1;
            }
            else {
                return rightHeight + 1;
            }
        }
        else {
            return 0;
        }
    }

    //h) zwrócenie napisowej reprezentacji drzewa
    string toString(TreeNode<T>* node, bool isRoot = true, string prefix = "", bool isLeft = false) {
        if (node == nullptr) {
            return "";
        }

        string result;
        string link = (isRoot) ? "" : (isLeft) ? "|" : "\\";

        if (isRoot) {
            result = "root: " + to_string(node->data);
        }
        else {
            result = prefix + link + "-- " + to_string(node->data);
        }

        if (node->left != nullptr || node->right != nullptr) {
            result += "\n";

            if (node->left != nullptr) {
                result += toString(node->left, false, prefix + (isRoot ? "" : (isLeft ? "|   " : "    ")), true);
            }

            if (node->right != nullptr) {
                result += toString(node->right, false, prefix + (isRoot ? "" : (isLeft ? "    " : "|   ")), false);
            }
        }

        return result;
    }


    //h) rekurencyjne wywołanie toString
    string ShowTree() {
        return toString(root);
    }

    //Funkcja pomocnicza
    int GenerateRandomInt() {
        int randomInt = rand() << 15;
        return randomInt;
    }
};

int main() {
    srand(2137);
    const int MAX_ORDER = 7;
    BinarySearchTree<int> bst;
    // dodawanie
    for (int o = 1; o <= MAX_ORDER; o++)
    {
        const int n = pow(10, o);
        auto t1 = high_resolution_clock::now();
        for (int i = 0; i < n; i++)
        {
            int randomInt = bst.GenerateRandomInt();
            bst.AddToTree(randomInt);
        }
        auto t2 = high_resolution_clock::now();
        auto time_to_add = duration_cast<milliseconds>(t2 - t1);
        cout << "Rozmiar drzewa: " << n << " Czas dodawania: " << time_to_add.count() << " milisekund" << endl;
        //zlozonosc = wysokosc drzewa /log2(n)
        int treeHeight = bst.TreeHeight(bst.root);
        double zlozonosc = treeHeight / log2(n);
        cout << "Zlozonosc obliczeniowa: " << zlozonosc << endl;
        if (n < 100) {
            cout << bst.ShowTree() << endl;
        }
        else {
            cout << "Drzewo zbyt duze, aby wyswietlic" << endl;
        }
    }


    // wyszukiwanie
    const int m = pow(10, 4); // liczba prob wyszukiwania
    int hits = 0; // liczba trafien
    auto t3 = high_resolution_clock::now();
    for (int i = 0; i < m; i++)
    {
        int randomIntToSearch = bst.GenerateRandomInt();
        TreeNode<int>* result = bst.Find(randomIntToSearch);
        if (result != NULL) {
            hits++;
        }
    }
    auto t4 = high_resolution_clock::now();
    auto time_to_find = duration_cast<milliseconds>(t4 - t3);
    cout << "Czas znajdowania: " << time_to_find.count() << " sekundy(y). Trafienia: " << hits << endl;
    /*
    TreeNode<int>* foundNode = bst.Find(420);

    list<int> PreOrderResult;
    bst.PreOrder(bst.root, PreOrderResult);
    for (int value : PreOrderResult) {
        cout << value << " ";
    }

    list<int> InOrderResult;
    bst.InOrder(bst.root, InOrderResult);
    for (int value : InOrderResult) {
        cout << value << " ";
    }

    int height = bst.TreeHeight(bst.root);
    cout << "Wysokość drzewa: " << height << endl;
    */

    bst.ClearTree(bst.root);
    //root = nullptr;
    return 0;
}