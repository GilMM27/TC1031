/*
    Written by: Gilberto Malagamba Montejo A00839075
    This code asks the user for a vector and uses their choice of sorting algorithm to sort it.
    Then, it asks the user for a number of searches and the elements to search, and uses linear and binary search to find them.
*/

#include <iostream>
#include <vector>

using namespace std;

// Sorting algorithms.

template <class T>
void exchangeSort(vector<T>& v) {
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                T aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

template <class T>
void bubbleSort(vector<T>& v) {
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - 1; j++) {
            if (v[j] > v[j + 1]) {
                T aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

template <class T>
void selectionSort(vector<T>& v) {
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    for (int i = 0; i < v.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        T aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

template <class T>
void insertionSort(vector<T>& v) {
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    for (int i = 1; i < v.size(); i++) {
        T aux = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

template <class T>
void merge(vector<T>& v, vector<T>& left, vector<T>& right) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            v[k] = left[i];
            i++;
        } else {
            v[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left.size()) {
        v[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size()) {
        v[k] = right[j];
        j++;
        k++;
    }
}

template <class T>
void mergeSort(vector<T>& v) {
    // Time complexity: O(n log n)
    // Space complexity: O(n)
    if (v.size() <= 1) {
        return;
    }
    vector<T> left;
    vector<T> right;
    int middle = v.size() / 2;
    for (int i = 0; i < middle; i++) {
        left.push_back(v[i]);
    }
    for (int i = middle; i < v.size(); i++) {
        right.push_back(v[i]);
    }
    mergeSort(left);
    mergeSort(right);
    merge(v, left, right);
}

template <class T>
int partition(vector<T>& v, int low, int high) {
    T pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

template <class T>
void quicksort(vector<T>& v, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(v, low, high);
        quicksort(v, low, pivotIndex - 1);
        quicksort(v, pivotIndex + 1, high);
    }
}

template <class T>
void quicksortWrapper(vector<T>& v) {
    // Time complexity: O(n log n)
    // Space complexity: O(log n)
    quicksort(v, 0, v.size() - 1);
}

// Search algorithms.

template <class T>
int linearSearch(vector<T>& v, T key) {
    // Time complexity: O(n)
    // Space complexity: O(1)
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            return i;
        }
    }
    return -1;
}

template <class T>
int binarySearch(vector<T>& v, T key) {
    // Time complexity: O(log n)
    // Space complexity: O(1)
    int low = 0;
    int high = v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (v[middle] == key) {
            return middle;
        }
        if (v[middle] < key) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return -1;
}

int main() {
    // User input.
    int n;
    cout << "Input the number of elements: ";
    cin >> n;
    vector<int> v;
    int aux;
    cout << "Input the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    cout << "Select the sorting algorithm:\n";
    cout << "1. exchangeSort\n";
    cout << "2. bubbleSort\n";
    cout << "3. selectionSort\n";
    cout << "4. insertionSort\n";
    cout << "5. mergeSort\n";
    cout << "6. quickSort\n";
    string input;
    cin >> input;
    if (input == "1") {
        exchangeSort(v);
    } else if (input == "2") {
        bubbleSort(v);
    } else if (input == "3") {
        selectionSort(v);
    } else if (input == "4") {
        insertionSort(v);
    } else if (input == "5") {
        mergeSort(v);
    } else if (input == "6") {
        quicksortWrapper(v);
    }
    cout << "Sorted vector:\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\nInput the number of searches: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Input the element to search: ";
        cin >> aux;
        cout << "Searching " << aux << " in the vector:\n";
        cout << "Linear search: " << linearSearch(v, aux) << endl;
        cout << "Binary search: " << binarySearch(v, aux) << endl;
    }
    return 0;
}

/*
Test cases:

Input the number of elements: 3
Input the elements: 5 1 3
Select the sorting algorithm:
1. exchangeSort
2. bubbleSort
3. selectionSort
4. insertionSort
5. mergeSort
6. quickSort
1
Sorted vector:
1 3 5 
Input the number of searches: 2
Input the element to search: 1
Searching 1 in the vector:
Linear search: 0
Binary search: 0
Input the element to search: 2
Searching 2 in the vector:
Linear search: -1
Binary search: -1

Input the number of elements: 4
Input the elements: 9 1 5 2
Select the sorting algorithm:
1. exchangeSort
2. bubbleSort
3. selectionSort
4. insertionSort
5. mergeSort
6. quickSort
5
Sorted vector:
1 2 5 9
Input the number of searches: 1
Input the element to search: 2 
Searching 2 in the vector:
Linear search: 1
Binary search: 1

Input the number of elements: 2
Input the elements: 1 2
Select the sorting algorithm:
1. exchangeSort
2. bubbleSort
3. selectionSort
4. insertionSort
5. mergeSort
6. quickSort
6
Sorted vector:
1 2
Input the number of searches: 3
Input the element to search: 2
Searching 2 in the vector:
Linear search: 1
Binary search: 1
Input the element to search: 1
Searching 1 in the vector:
Linear search: 0
Binary search: 0
Input the element to search: 0
Searching 0 in the vector:
Linear search: -1
Binary search: -1

Input the number of elements: 6
Input the elements: 230194 52903 432 105 4390 234
Select the sorting algorithm:
1. exchangeSort
2. bubbleSort
3. selectionSort
4. insertionSort
5. mergeSort
6. quickSort
2
Sorted vector:
105 234 432 4390 52903 230194
Input the number of searches: 0
*/