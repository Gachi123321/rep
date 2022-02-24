#include "String.h"

using namespace BMSTU;

string::string() : _size_str(0), _str_ptr(new char[1])
{
    *_str_ptr = '\0';
}

string::string(size_t size) : _size_str(size), _str_ptr(new char[size+1])
{
    _fill(_str_ptr, _size_str, ' ');
}

string::string(const char *c_str)
{
    _size_str = _strlen(c_str);
    _str_ptr = new char[_size_str+1];
    for(size_t i = 0; i < _size_str + 1; ++ i)
    {
        _str_ptr[i] = c_str[i];
    }
}

string::string(const BMSTU::string &other_string)
{
    _size_str = other_string.size();
    _str_ptr = new char[_size_str+1];
    for(size_t i  = 0; i < _size_str + 1; ++i)
    {
        _str_ptr[i] = other_string.c_str()[i];
    }
}

string &string::operator+=(const BMSTU::string &other_string)
{
    string new_str(_str_ptr);
    delete[] _str_ptr;
    _size_str = new_str.size() + other_string.size();
    _str_ptr = new char[_size_str + 1];
    for(size_t i = 0; i < new_str.size(); ++i)
    {
        _str_ptr[i] = new_str.c_str()[i];
    }
    for(size_t i = new_str.size(); i < _size_str + 1; ++i)
    {
        _str_ptr[i] = other_string.c_str()[i - new_str.size()];
    }
    return *this;
}

string &string::operator=(const BMSTU::string &other_string)
{
    if(this != &other_string)
    {
        delete[] _str_ptr;
        _size_str = other_string.size();
        _str_ptr = new char[_size_str + 1];
        for (size_t i = 0; i < _size_str + 1; ++i) {
            _str_ptr[i] = other_string.c_str()[i];
        }
    }
    return *this;
}

string &string::operator=(const char *other_c_str)
{
    delete[] _str_ptr;
    _size_str = _strlen(other_c_str);
    _str_ptr = new char[_size_str+1];
    for(size_t i = 0; i < _size_str+1; ++i)
    {
        _str_ptr[i] = other_c_str[i];
    }
    return *this;
}

string &string::operator=(const int number)
{
    delete[] _str_ptr;

    int copy_number = number;

    _size_str = _intlen(copy_number);
    _str_ptr = new char[_size_str];

    bool isNegative = false;
    if (copy_number < 0)
    {
        isNegative = true;
        copy_number *= -1;
    }

    char symbols[_size_str];
    for(size_t i = 0; i < _size_str; ++i)
    {
        if(isNegative &&  i == (_size_str - 1))
        {
            symbols[i] = '-';
            copy_number /= 10;
        }
        else
        {
            symbols[i] = (copy_number % 10) + '0';
            copy_number /= 10;
        }
    }

    for(size_t i = 0; i < _size_str; ++i)
    {
        _str_ptr[i] = symbols[_size_str - 1 - i];
    }

    return *this;
}

std::ostream &BMSTU::operator<<(std::ostream &out, const string &item)
{
    out << item.c_str();
    return out;
}

void string::swap(BMSTU::string &first, BMSTU::string &second)
{
    string swaper = first;
    first = second;
    second = swaper;
}

const char *string::c_str() const
{
    return _str_ptr;
}

const size_t string::size() const
{
    return _size_str;
}

void string::_fill(char *str, size_t size, char value) {

    for(size_t i = 0; i < size; i++) {

        str[i] = value;
    }
     str[size] = '\0';
}

size_t string::_strlen(const char *str) {
    size_t len = 0;
    while(*str) {

     }
        len++;

        str++;
     }
    return len;
size_t string::_intlen(const int number)
{
    int copy_number = number;
    size_t length_number = 0;

    while (copy_number != 0)
    {
        if (copy_number < 0)
        {
            copy_number *= -1;
            ++length_number;
        }
        else
        {
            copy_number /= 10;
            ++length_number;
        }
    }

    return length_number;
}

string::~string()
{
    delete[] _str_ptr;
}