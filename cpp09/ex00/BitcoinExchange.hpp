#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> exchangeRateMap;

        void loadDataBase(std::ifstream &dataBaseFile);
        void populateMap(const std::string &dataBaseFile);
        bool isValidDateFormat(const std::string &date);
        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value);
        void processQuery(std::string &date, std::string &value);

    public:
        BitcoinExchange(std::ifstream &dataBaseFile);
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange &operator=(const BitcoinExchange &source);
        ~BitcoinExchange();

        void processInputFile(std::ifstream &inputFile);

};

#endif // BITCOINEXCHANGE_HPP
