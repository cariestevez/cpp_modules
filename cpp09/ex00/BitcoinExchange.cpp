#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &dataBaseFile)
{
    std::cout << "\e[0;103mBitcoinExchange::\e[0m Default constructor called" << std::endl;
    loadDataBase(dataBaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
{
    std::cout << "\e[0;103mBitcoinExchange::\e[0m Copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
    if (this != &source)
        //code
	
    std::cout << "\e[0;103mBitcoinExchange::\e[0m Assignment operator used" << std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "\e[0;103mBitcoinExchange::\e[0m Destructor called" << std::endl;
}

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
        if (validLine)
            exchangeRateMap[date] = rate;
        else
            std::cout << "Skipping invalid line in data base => " << line << std::endl;
    }
    
    db.close();

    if (exchangeRateMap.empty())
        std::cout << "Error: No valid values could be extracted from database. Provide a valid one." << std::endl;
    
    return ;

}

//////////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::processQuery(std::string &date, std::string &value)
{
    float floatValue = std::stof(value);

    // Check if the provided form name exists in the map
    std::map<std::string, float>::const_iterator it = exchangeRateMap.find(date);
	if (it != exchangeRateMap.end())//if it didn't arrive at the end => coincidence found
	{
        //exchange rate * floatValue
        it->second * floatValue;
        std::cout << it->first << " => " << it->second << " = " << it->second * floatValue << std::endl;
		
    } 
	else
	{
        //search for the last exchange date and do the same as above
        //else return error messages in case the calculation results are wrong, but at this point the input has been checked
        //maybe do some more checks for the rate before saving into map?
    }
}

void BitcoinExchange::processInputFile(std::ifstream &inputFile)
{
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string date, separator, value;
        if (!(iss >> date >> separator >> value) || !iss.eof() || separator != "|")//separes the line by whitespaces and saves in each of the variables
        {
            std::cout << "Error: bad formatted line." << std::endl;
            continue;
        }
        if (date != "date" && !(isValidDateFormat(date) && isValidDate(date)))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (value != "value" && !(isValidValue(value)))
            continue;
        
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
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
    try
    {
        float floatValue = std::stof(value);
        if (floatValue < 0)
        {
            std::cout << "Error! not a positive number." << std::endl;
            return false;
        }
        if (floatValue > 1000)
        {
            std::cout << "Error! too large a number." << std::endl;
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