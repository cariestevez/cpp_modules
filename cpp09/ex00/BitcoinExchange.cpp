#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &dataBaseFile)
{
    loadDataBase(dataBaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source) : exchangeRateMap(source.exchangeRateMap) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
    if (this != &source)
        exchangeRateMap = source.exchangeRateMap;

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

//////////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::loadDataBase(const std::string &dataBaseFile)
{
    std::ifstream db(dataBaseFile);
    if (!db)
    {
        std::cerr << "Error: could not open data base file." << std::endl;
        return;
    }

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
            if (ss >> rate && iss.eof() && isValidDateFormat(date))//improve the conversion to float of the rate?
                validLine = true;
        }
        if (validLine && date != "date")
            exchangeRateMap[date] = rate;
        else
            std::cout << "Skipping (invalid) line in data base => " << line << std::endl;
    }
    
    db.close();

    if (exchangeRateMap.empty())
        std::cout << "Error: No valid values could be extracted from database. Please provide a valid one." << std::endl;
    
    //std::cout << "database parsed successfully" << std::endl;
    return ;

}

//////////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::processQuery(std::string &date, std::string &value)
{
    float floatValue = std::stof(value);

    std::map<std::string, float>::const_iterator iter = exchangeRateMap.lower_bound(date);

    //std::cout << "return of lower bound iter: " << iter->first << std::endl;
    if (iter->first == date)
    {
        std::cout << date << " => " << value << " = " << iter->second * floatValue << std::endl;
    }
    else if (iter->first > date && iter == exchangeRateMap.begin())
    {
        std::cout << "Error: date " << date << " is before the oldest date in the database." << std::endl;
    }
    else
    {
        // If no exact match, use the closest previous date
        std::map<std::string, float>::const_iterator prev = std::prev(iter);
        std::cout << date << " => " << value << " = " << prev->second * floatValue << std::endl;
    }
}

void BitcoinExchange::processInputFile(std::ifstream &inputFile)
{
    std::string line;
    while (std::getline(inputFile, line))
    {
        //std::cout << line << std::endl;
        std::istringstream iss(line);
        std::string date, separator, value;
        if (!(iss >> date) || (date != "date" && !(isValidDateFormat(date) && isValidDate(date))))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!(iss >> separator >> value) || !iss.eof() || separator != "|")//separes the line by whitespaces and saves in each of the variables
        {
            std::cout << "Error: bad formatted line." << std::endl;
            continue;
        }
        if (value != "value" && !(isValidValue(value)))
            continue;
        if (date != "date" && value != "value")
            processQuery(date, value);
    }

    return;
}

bool BitcoinExchange::isValidDateFormat(const std::string &date)
{
    std::regex dateRegex("\\d{4}-\\d{2}-\\d{2}");
    return std::regex_match(date, dateRegex);
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
    std::regex floatRegex("^[+-]?([0-9]*[.])?[0-9]+$");

    if (!std::regex_match(value, floatRegex))
    {
        std::cout << "Error: number not of valid type." << std::endl;
        return false;
    }
    try
    {
        float floatValue = std::stof(value);
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
    }
    catch (const std::invalid_argument &ia)
    {
        std::cerr << "Error: Conversion to float not possible. Invalid argument: " << ia.what() << std::endl;
        return false;
    }
    catch (const std::out_of_range &oor)
    {
        std::cerr << "Error: Conversion to float not possible. Out of range: " << oor.what() << std::endl;
        return false;
    }

    return true;
}

//////////////////////////////////////////////////////////////////////////////////////