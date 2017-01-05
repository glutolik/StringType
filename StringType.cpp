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

    bool straight = str_like(m_str, m_pattern, n, m);
    std::reverse(m_str.begin(), m_str.end());
    std::reverse(m_pattern.begin(), m_pattern.end());
    bool reversed = str_like(m_str, m_pattern, n, m);

    return straight || reversed;
}


bool str_like(const std::string& m_str, const std::string& m_pattern, size_t n, size_t m){
    size_t j = 0, k = 0, l = 0;

    for(size_t i = 0; i < n; ++i){
        k = i;

        if(m_pattern[i] == '%'){
            std::cout << "% " << j << std::endl;
            while((m_pattern[k] == '%') && k < n){
                ++k;
            }
            if(k == n){
                std::cout << "true 1" << std::endl;
                return true;
            }
            else
                i = k - 1;
            if(m_pattern[k] != '_'){
                while(m_str[j] != m_pattern[k] && j < m){
                    ++j;
                }
            }
        }
        else if(m_pattern[i] == '_'){
            std::cout << "_ " << j << std::endl;
            j++;
        }
        else if(m_pattern[i] != m_str[j]){
            std::cout << "exit 2" << std::endl;
            return false;
        }
        else
            ++j;
        if(j >= m + 1){
            std::cout << "exit 3" << std::endl;
            return false;
        }
    }
    if(j < m){
        std::cout << "exit 4 " << j << std::endl;
        return false;
    }
    else
        return true;
}
