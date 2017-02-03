#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
#include <time.h>

class StringType{
private:
    const char* m_str;
    size_t m_size;
public:
    StringType() {}
    StringType(const char* str, size_t size) : m_str(str),
    m_size(size)
    {}
    StringType(const char* str) : StringType(str, strlen(str))
    {}
    StringType(std::string str) : StringType(str.c_str(), strlen(str.c_str()))
    {}

    ~StringType() {}

    size_t get_size() const{
        return m_size;
    }
    const char* get_str() const{
        return m_str;
    }
};

class Like
{
private:
    StringType pattern;
    char escape;
    bool ignorecase;
public:
    Like(): escape('\\'), ignorecase(false) {}
    Like(const StringType& p, char esc = '\\', bool ignore = false): pattern(p), escape(esc), ignorecase(ignore) {}

    ~Like() {}

    bool match(const StringType& str) const;
};

bool like( const StringType& str, const StringType& pattern, char escape = '\\', bool ignorecase = false);
bool str_like(const std::string& m_str, const std::string& m_pattern);

bool stack_like( const StringType& str, const StringType& pattern, char escape = '\\', bool ignorecase = false);
bool stack_str_like(const std::string& m_str, const std::string& m_pattern);
