#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &dataBaseFile)
{
    loadDataBase(dataBaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source) : exchangeRateMap(source.exchangeRateMap) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
    if (this != &source)
    {
       exchangeRateMap = source.exchangeRateMap;
    }
    
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

//////////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::loadDataBase(std::ifstream &db)
{
    std::string line;
    std::getline(db, line);
    while (std::getline(db, line))
    {
        bool validLine = false;
        std::istringstream iss(line);
        std::string date, rateStr;
        float rate;
        if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
        {
            std::istringstream ss(rateStr);
            if (ss >> rate && iss.eof() && isValidDateFormat(date))
                validLine = true;
        }
        if (validLine && date != "date")
            exchangeRateMap[date] = rate;
        else
            std::cout << "Skipping (invalid) line in data base => " << line << std::endl;
    }
    
    db.close();
    
    return ;
}

//////////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::processQuery(std::string &date, std::string &value)
{
    float floatValue = std::atof(value.c_str());

    std::map<std::string, float>::const_iterator iter = exchangeRateMap.lower_bound(date);

    if (iter != exchangeRateMap.end() && iter->first == date)
    {
        std::cout << date << " => " << value << " = " << iter->second * floatValue << std::endl;
    }
    else if (iter == exchangeRateMap.begin())
    {
        std::cout << "Error: date " << date << " is before the oldest date in the database." << std::endl;
    }
    else
    {
        std::cout << date << " => " << value << " = " << (--iter)->second * floatValue << std::endl;
    }
}

void BitcoinExchange::processInputFile(std::ifstream &inputFile)
{
    if (exchangeRateMap.empty())
    {
        std::cout << "Error: No valid values could be extracted from database. Please provide a valid one." << std::endl;
        return ;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string date, separator, value;
        if (!(iss >> date) || (date != "date" && !(isValidDateFormat(date) && isValidDate(date))))
        {
            if (!(iss >> date))
                std::cout << "Error: empty line" << date << std::endl;
            else
                std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!(iss >> separator >> value) || !iss.eof() || separator != "|")//separes the line by whitespaces and saves in each of the variables
        {
            std::cout << "Error: bad formatted line." << std::endl;
            continue;
        }
        if (value != "value" && !(isValidValue(value)))
        {
            continue;
        }
        if (date != "date" && value != "value")
        {
            processQuery(date, value);
        }
    }

    return;
}

bool BitcoinExchange::isValidDateFormat(const std::string &date)
{
    if (date.size() != 10)
        return false;

    for (int i = 0; i < 4; i++)
    {
        if (!(isdigit(date[i])))
            return false;
    }
    if (date[4] != '-')
        return false;
    for (int i = 5; i < 7; i++)
    {
        if (!(isdigit(date[i])))
            return false;
    }
    if (date[7] != '-')
        return false;
    for (int i = 8; i < 10; i++)
    {
        if (!(isdigit(date[i])))
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    int year, month, day;
    char delimiter1, delimiter2;

    if (!(std::istringstream(date) >> year >> delimiter1 >> month >> delimiter2 >> day))
        return false;
    if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
    std::istringstream iss(value);
    float floatValue;
    char remain;

    if (!(iss >> floatValue) || (iss >> remain))
    {
        std::cout << "Error: invalid value." << std::endl;
        return false;
    }
    if (floatValue < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (floatValue > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

//////////////////////////////////////////////////////////////////////////////////////