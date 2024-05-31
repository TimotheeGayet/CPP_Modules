#include "Pmergeme.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

Pmergeme::Pmergeme()
{
}

Pmergeme::Pmergeme(const Pmergeme &other)
{
    (void)other;
}

Pmergeme &Pmergeme::operator=(const Pmergeme &other)
{
    (void)other;
    return *this;
}

Pmergeme::~Pmergeme()
{
}

template <typename Container>
Container &FJMerge(Container &arr, int groups_size = 2)
{
    if (static_cast<size_t>(groups_size) > arr.size())
        return arr;

    for (typename Container::iterator it = arr.begin(); it <= arr.end() - groups_size; it += groups_size)
    {
        if (*(it + (groups_size / 2) - 1) > *(it + groups_size - 1))
        {
            std::swap_ranges(it, it + groups_size / 2, it + groups_size / 2);
        }
    }

    return FJMerge(arr, groups_size * 2);
}

template <typename Container>
Container &FJInsert(Container &arr, int groups_size)
{
    int uneven = arr.size() % 2;
    int temp;

    if (uneven)
    {
        temp = arr[arr.size() - 1];
        arr.pop_back();
    }

    (void)temp;

    std::rotate(arr.begin(), arr.begin() + groups_size / 2, arr.begin() + groups_size - 1);
    std::rotate(arr.end() - 2 - groups_size / 2, arr.end() - 2, arr.end() - 2);

    return arr;
}

template <typename Container>
Container &fordJohnsonSort(Container &arr)
{
    FJMerge(arr);
    FJInsert(arr, (arr.size() - (arr.size() % 2)));
    return arr;
}

Pmergeme::Pmergeme(int argc, char **argv)
{
    std::vector<int> arr1;
    std::deque<int> arr2;
    for (int i = 1; i < argc; i++)
    {
        arr1.push_back(atoi(argv[i]));
        arr2.push_back(atoi(argv[i]));
    }

    clock_t start = clock();
    fordJohnsonSort(arr1);
    clock_t end = clock();

    std::cout << "After sort: " << std::endl;
    for (std::vector<int>::iterator it = arr1.begin(); it != arr1.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Vector sort: " << std::fixed << std::setprecision(5) << elapsed << "s" << std::endl;

    start = clock();
    fordJohnsonSort(arr2);
    end = clock();

    elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Deque sort: " << std::fixed << std::setprecision(5) << elapsed << "s" << std::endl;
}
