#include "Pmergeme.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

Pmergeme::Pmergeme() {
}

Pmergeme::Pmergeme(const Pmergeme& other) {
    (void)other;
}


Pmergeme& Pmergeme::operator=(const Pmergeme& other) {
    (void)other;
    return *this;
}

Pmergeme::~Pmergeme() {
}

template <typename Container>
void insertionSort(Container& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <typename Container>
void merge(Container& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Container L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename Container>
void fordJohnsonSort(Container& arr, int left, int right) {
    if (left < right) {
        if (right - left + 1 < 10) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            fordJohnsonSort(arr, left, mid);
            fordJohnsonSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}

Pmergeme::Pmergeme(int argc, char **argv)
{
    std::vector<int> arr;
    std::deque<int> arr2;
    for (int i = 1; i < argc; i++)
    {
        arr.push_back(atoi(argv[i]));
        arr2.push_back(atoi(argv[i]));
    }

    clock_t start = clock();
    fordJohnsonSort(arr, 0, arr.size() - 1);
    clock_t end = clock();
    double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "list sort: " << std::endl;
    for (std::size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << "Vector sort: " << std::fixed << std::setprecision(5) << elapsed << "s" << std::endl;

    start = clock();
    fordJohnsonSort(arr2, 0, arr2.size() - 1);
    end = clock();
    elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Deque sort: " << std::fixed << std::setprecision(5) << elapsed << "s" << std::endl;
}