#pragma once

#include <iostream>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <utility>

class PmergeMe
{
    public:
        template <typename Container>
        static Container argvToContainer(const char **argv) {
            Container container;
            double nb;
            char *endPtr;

            while (*argv)
            {
                if (**argv == '\0')
                    throw(BadInputException());

                nb = std::strtod(*argv, &endPtr);

                if (nb > std::numeric_limits<int>::max() || *endPtr != '\0')
                    throw(BadInputException());
                else if (nb < 0)
                    throw(BadInputException());

                container.push_back(static_cast<int>(nb));

                argv++;
            }

            return (container);
        };

        template <typename Container, typename PairListContainer>
        static void sortContainer(Container &container) {
            PairListContainer pair;
            int tmp = -1;

            if (container.size() <= 1)
                return;

            if (container.size() % 2 != 0)
            {
                tmp = container.back();
                container.pop_back();
            }

            pair = _pairingContainer<Container, PairListContainer>(container);
            _mergeSortPair(pair);
            _insertFirst(container, pair, tmp);
            _insertSecond(container, pair);
        };

        class BadInputException : public std::exception {
            public:
                virtual const char *what(void) const throw();
        };

    private:
        PmergeMe(void);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe(void);

        template <typename Container, typename PairListContainer>
        static PairListContainer _pairingContainer(Container &container) {
            std::pair<int, int> pairTmp;
            PairListContainer pair;

            for (typename Container::iterator it = container.begin(); it != container.end(); it++)
            {
                if (*(it + 1) > *it)
                {
                    pairTmp.second = *(it++);
                    pairTmp.first = *it;
                }
                else
                {
                    pairTmp.first = *(it++);
                    pairTmp.second = *it;
                }
                pair.push_back(pairTmp);
            }

            container.clear();

            return (pair);
        };

        template <typename Container>
        static void _mergeSortPair(Container &pair) {

            Container first;
            Container second;

            _splitPair(pair, first, second);

            if (first.size() > 1)
                _mergeSortPair(first);
            if (second.size() > 1)
                _mergeSortPair(second);

            _mergePair(pair, first, second);
        }

        template <typename Container>
        static void _mergePair(Container &pair, Container &first, Container &second) {

            typename Container::iterator it_first = first.begin();
            typename Container::iterator it_second = second.begin();

            while (it_first != first.end() || it_second != second.end())
            {
                if (it_second == second.end() || (it_first != first.end() && it_first->first < it_second->first))
                {
                    pair.push_back(*it_first);
                    it_first++;
                }
                else
                {
                    pair.push_back(*it_second);
                    it_second++;
                }
            }
        }

        template <typename Container>
        static void _splitPair(Container &pair, Container &first, Container &second) {
            int i = pair.size() / 2;

            for (typename Container::iterator it = pair.begin(); it != pair.end(); it++)
            {
                if (i-- > 0)
                    first.push_back(*it);
                else
                    second.push_back(*it);
            }

            pair.clear();
        }

        template <typename Container, typename PairListContainer>
        static void _insertFirst(PairListContainer &container, Container &pair, int uneven_nbr) {
            container.push_back(pair.front().second);

            for (typename Container::iterator it = pair.begin(); it != pair.end(); it++)
                container.push_back(it->first);

            if (uneven_nbr != -1)
            {
                std::pair<int, int> pairTmp;

                pairTmp.first = -1;
                pairTmp.second = uneven_nbr;
                pair.push_back(pairTmp);
            }
        };

        template <typename Container, typename PairListContainer>
        static void _insertSecond(PairListContainer &container, Container &pair) {
            size_t sizeGoup = 0;
            size_t index = 0;

            for (size_t i = 0; index < pair.size() - 1; i++)
            {
                sizeGoup = (1 << (i + 1)) - sizeGoup;
                index += sizeGoup;

                if (index > pair.size() - 1)
                {
                    sizeGoup += pair.size() - 1 - index;
                    index = pair.size() - 1;
                }

                for (size_t j = 0; j < sizeGoup; j++)
                    _dichotomicResearch(container, pair[index - j]);
            }
        };

        template <typename Container>
        static void _dichotomicResearch(Container &container, const std::pair<int, int> &pair) {
            typename Container::iterator it = container.begin();
            typename Container::iterator it_end = find(container.begin(), container.end(), pair.first);

            container.insert(std::upper_bound(it, it_end, pair.second), pair.second);
        };
};
