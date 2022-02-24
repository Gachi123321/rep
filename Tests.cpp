#include <gtest/gtest.h>
#include "String.h"

using namespace BMSTU;

TEST(StringTest, default_string)
{
    string str;
    ASSERT_EQ(str.size(), 0);
    ASSERT_STREQ(str.c_str(), "");
}

TEST(StringTest, size_string)
{
    string str(5);
    ASSERT_EQ(str.size(), 5);
    ASSERT_STREQ(str.c_str(), "     ");
}

TEST(StringTest, char_string)
{
    string str("Hello");
    ASSERT_EQ(str.size(), 5);
    ASSERT_STREQ(str.c_str(), "Hello");
}

TEST(StringTest, bmstu_string)
{
    string str1("Hello");
    string str2(str1);
    ASSERT_EQ(str2.size(), 5);
    ASSERT_STREQ(str2.c_str(), "Hello");
}

TEST(StringTest, assigment_plus)
{
    string str1 = ", World!";
    string str2 = "Hello";
    str2 += str1;
    ASSERT_EQ(str2.size(), 13);
    ASSERT_STREQ(str2.c_str(), "Hello, World!");
}

TEST(StringTest, assigment_char)
{
    string str = "Hello";
    ASSERT_EQ(str.size(), 5);
    ASSERT_STREQ(str.c_str(), "Hello");
}

TEST(StringTest, assigment_bmstu)
{
    string str = "Hello";
    string str2 = str;
    ASSERT_EQ(str.size(), 5);
    ASSERT_STREQ(str.c_str(), "Hello");
    str2 = str2;
    ASSERT_EQ(str.size(), 5);
    ASSERT_STREQ(str.c_str(), "Hello");
}

TEST(StringTest, output_operator)
{
    std::ostringstream out;
    string str = "Dungeon";
    out << str;
    ASSERT_EQ(out.str(), "Dungeon");
}

TEST(StringTest, swap_operator)
{
    string str1 = "Dungeon";
    string str2 = "Master";
    string::swap(str1, str2);
    ASSERT_EQ(str1.size(), 7);
    ASSERT_STREQ(str1.c_str(), "Master");
    ASSERT_EQ(str2.size(), 4);
    ASSERT_STREQ(str2.c_str(), "Dungeon");
}

TEST(StringTest, assigment_number)
{
    string str;
    str = -100500;
    ASSERT_EQ(str.size(), 7);
    ASSERT_STREQ(str.c_str(), "-100500");
}