#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class Data {
    private :
        Data(const Data &other);
        Data &operator=(const Data &other);
        std::map<std::string, double> _data;

    public :
        Data();
        Data(std::ifstream &file);
        ~Data();
        std::map<std::string, double> getData();
        void printData();
        bool btcPriceCompare(std::istream& input);
        bool parseData(const std::string& filename);
        double getBitcoinPrice(const std::string& date);
        bool isNumeric(const std::string& str, int flag);
        bool isValidDate(const std::string& date, const std::string& line);

        class negativeNumber : public std::exception {
            public :
                virtual const char* what() const throw();
        };

        class badInput : public std::exception {
        public:
            badInput(const std::string& line) : _line(line) {}
            virtual const char* what() const throw();
            virtual ~badInput() throw() {}
        private:
            std::string _line;
        };

        class tooLargeNumber : public std::exception {
            public :
                virtual const char* what() const throw();
        };
};

#endif