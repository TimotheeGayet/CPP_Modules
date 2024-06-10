#pragma once

#include <iostream>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <utility>

class PmergeMe
{
public:
    template <typename T>
    static T convertToContainer(const char **strTab)
    {
        T container;
        double nb;
        char *endPtr;

        while (*strTab)
        {
            if (**strTab == '\0')
                throw(BadInputException());

            nb = std::strtod(*strTab, &endPtr);

            if (nb > std::numeric_limits<int>::max() || *endPtr != '\0')
                throw(BadInputException());
            else if (nb < 0)
                throw(BadInputException());

            container.push_back(static_cast<int>(nb));

            strTab++;
        }

        return (container);
    };

    template <typename T>
    static void sortContainer(T &container)
    {
        U list_of_pairs;
        int uneven_nbr = -1;

        if (container.size() <= 1)
            return;

        if (container.size() % 2 != 0)
        {
            uneven_nbr = container.back();
            container.pop_back();
        }

        list_of_pairs = _pairingContainer<T>(container);
        _sortPair(list_of_pairs);
        _mergeSortPair(list_of_pairs);
        _insertFirst(container, list_of_pairs, uneven_nbr);
        _insertSecond(container, list_of_pairs);
    };

    class BadInputException : public std::exception
    {
    public:
        virtual const char *what(void) const throw();
    };

private:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    template <typename T>
    static T _pairingContainer(T &container)
    {
        T pair;
        T pairsList;

        for (typename T::iterator it = container.begin(); it != container.end(); it++)
        {
            pair.push_back(it++);
            pair.push_back(*it);
            pairsList.push_back(pair);
        }

        container.clear();

        return (pairsList);
    };

    template <typename T>
    static void _sortPair(T &list_of_pairs)
    {
        int temp_to_swap;

        for (typename T::iterator it = list_of_pairs.begin(); it != list_of_pairs.end(); it++)
        {
            if (it->first < it->second)
            {
                temp_to_swap = it->first;
                it->first = it->second;
                it->second = temp_to_swap;
            }
        }
    };

    template <typename T>
    static void _mergeSortPair(T &list_of_pairs)
    {
        T first;
        T second;

        _splitPair(list_of_pairs, first, second);

        if (first.size() > 1)
            _mergeSortPair(first);
        if (second.size() > 1)
            _mergeSortPair(second);

        _mergePair(list_of_pairs, first, second);
    }

    template <typename T>
    static void _splitPair(T &list_of_pairs, T &first, T &second)
    {
        int i = list_of_pairs.size() / 2;

        for (typename T::iterator it = list_of_pairs.begin(); it != list_of_pairs.end(); it++)
        {
            if (i-- > 0)
                first.push_back(*it);
            else
                second.push_back(*it);
        }

        list_of_pairs.clear();
    }

    template <typename T>
    static void _mergePair(T &list_of_pairs, T &first, T &second)
    {
        typename T::iterator it_first = first.begin();
        typename T::iterator it_second = second.begin();

        while (it_first != first.end() || it_second != second.end())
        {
            if (it_second == second.end() || (it_first != first.end() && it_first->first < it_second->first)) // not sure about the < condition
            {
                list_of_pairs.push_back(*it_first);
                it_first++;
            }
            else
            {
                list_of_pairs.push_back(*it_second);
                it_second++;
            }
        }
    }

    template <typename T>
    static void _insertFirst(T &container, T &list_of_pairs, int uneven_nbr)
    {
        container.push_back(list_of_pairs.front().back());

        for (typename T::iterator it = list_of_pairs.begin(); it != list_of_pairs.end(); it++)
            container.push_back(it->first);

        if (uneven_nbr != -1)
        {
            T temporary_pair;

            temporary_pair.push_back() = -1;
            temporary_pair.push_back() = uneven_nbr;
            list_of_pairs.push_back(temporary_pair);
        }
    };

    template <typename T>
    static void _insertSecond(T &container, T &list_of_pairs)
    {
        size_t sizeGroup = 0;
        size_t index = 0;

        for (size_t i = 0; index < list_of_pairs.size() - 1; i++)
        {
            sizeGroup = (1 << (i + 1)) - sizeGroup;
            index += sizeGroup;

            if (index > list_of_pairs.size() - 1)
            {
                sizeGroup += list_of_pairs.size() - 1 - index;
                index = list_of_pairs.size() - 1;
            }

            for (size_t j = 0; j < sizeGroup; j++)
                _dichotomicResearch(container, list_of_pairs[index - j]);
        }
    };

    template <typename T>
    static void _dichotomicResearch(T &container, const T &pair)
    {
        typename T::iterator it = container.begin();
        typename T::iterator it_end = find(container.begin(), container.end(), pair.begin());

        container.insert(std::upper_bound(it, it_end, pair.back()), pair.back());
    };
};
