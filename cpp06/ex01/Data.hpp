#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data
{
    private:
        int         _intValue;
        float       _floatValue;
        std::string _stringValue;

    public:
        Data(void);
        Data(const Data &source);
        Data &operator=(const Data &source);
        ~Data();
        
        Data(int i, float f, const std::string& s);

        const int &getInt(void) const;
        const float &getFloat(void) const;
        const std::string &getString(void) const;
};

#endif