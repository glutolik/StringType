#include "StringType.h"

bool like( const StringType& str, const StringType& pattern, char escape, bool ignorecase){
    size_t n = pattern.get_size();
    size_t m = str.get_size();
    std::string m_str = str.get_str();
    std::string m_pattern = pattern.get_str();

    if(ignorecase){
        std::transform(m_str.begin(), m_str.end(), m_str.begin(), tolower);
        std::transform(m_pattern.begin(), m_pattern.end(), m_pattern.begin(), tolower);
    }
    return str_like(m_str, m_pattern);
}

bool str_like(const std::string& m_str, const std::string& m_pattern){
    size_t i = 0;
    if(m_pattern.length() == 0 && m_str.length() != 0){
        //std::cout << "exit 1" << std::endl;
        return 0;
    }
    else if(m_pattern.length() == 0 && m_str.length() == 0){
        //std::cout << "exit 2" << std::endl;
        return 1;
    }
    else if(m_pattern[0] == '%'){
        if(m_str.length() != 0){
            for(i = 0; i <=
             m_str.length(); ++i){
                if(str_like(m_str.substr(i, m_str.length() - i), m_pattern.substr(1, m_pattern.length() - 1)) == 1){
                    //std::cout << "exit % 1" << std::endl;
                    return 1;
                }
            }
            //std::cout << "exit % 0" << std::endl;
            return 0;
        }
        else{
            return str_like(m_str, m_pattern.substr(1, m_pattern.length() - 1));
        }
    }
    else if(m_pattern[0] == '_'){
        if(m_str.length() == 0)
            return 0;
        else
            return str_like(m_str.substr(1, m_str.length() - 1), m_pattern.substr(1, m_pattern.length() - 1));
    }
    else if(m_pattern[0] == m_str[0]){
        return str_like(m_str.substr(1, m_str.length() - 1), m_pattern.substr(1, m_pattern.length() - 1));
    }
    else
        return 0;
}

bool Like::match(const StringType& str) const{
    return like(str, pattern);
}
