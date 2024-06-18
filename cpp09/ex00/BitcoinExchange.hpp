#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> exchangeRateMap;

        void loadDataBase(const std::string &dataBaseFile);
        void populateMap(const std::string &dataBaseFile);
        bool isValidDateFormat(const std::string &date);
        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value);
        void processQuery(std::string &date, std::string &value);

    public:
        BitcoinExchange(const std::string &dataBaseFile);
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange &operator=(const BitcoinExchange &source);
        ~BitcoinExchange();

        void processInputFile(std::ifstream &inputFile);

};

#endif // BITCOINEXCHANGE_HPP
