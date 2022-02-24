#include <iostream>
#include <ostream>

#pragma once
namespace BMSTU {
    class string {
    public:
        string();
        string(size_t size);
        string(const char *c_str);
        string(const BMSTU::string &other_string);

        string &operator+=(const BMSTU::string &other_string);
        string &operator=(const BMSTU::string &other_string);
        string &operator=(const char *other_c_str);
        string &operator=(const int number);

        friend std::ostream &operator<<(std::ostream &out, const string &item);

        ~string();

        const char *c_str() const;
        const size_t size() const;

        static void swap(BMSTU::string &first, BMSTU::string &second);

    private:
        char *_str_ptr;
        size_t _size_str;
        void _fill(char *str, size_t size, char value);
        static size_t _strlen(const char *str);
        static size_t _intlen(const int number);
    };
}