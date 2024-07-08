#include "Data.hpp"

Data::Data(void) {}

Data::Data(int i, float f, const std::string& s) : _intValue(i), _floatValue(f), _stringValue(s) {}

Data::Data(const Data &source) : _intValue(source._intValue), _floatValue(source._floatValue), _stringValue(source._stringValue) {}

Data &Data::operator=(const Data &source)
{
	if (this != &source)
    {
        _intValue = source._intValue;
        _floatValue = source._floatValue;
        _stringValue = source._stringValue;
    }
	  
	return (*this);
}

Data::~Data() {}

//////////////////////////////////////////////////////////////////////////////////////

const int &Data::getInt(void) const { return _intValue; }
const float &Data::getFloat(void) const { return _floatValue; }
const std::string &Data::getString(void) const { return _stringValue; }