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
        return 0;
    }
    else if(m_pattern.length() == 0 && m_str.length() == 0){
        return 1;
    }
    else if(m_pattern[0] == '%'){
        if(m_str.length() != 0){
            for(i = 0; i <=
             m_str.length(); ++i){
                if(str_like(m_str.substr(i, m_str.length() - i), m_pattern.substr(1, m_pattern.length() - 1)) == 1){
                    return 1;
                }
            }
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

bool stack_like( const StringType& str, const StringType& pattern, char escape, bool ignorecase){
    size_t n = pattern.get_size();
    size_t m = str.get_size();
    std::string m_str = str.get_str();
    std::string m_pattern = pattern.get_str();

    if(ignorecase){
        std::transform(m_str.begin(), m_str.end(), m_str.begin(), tolower);
        std::transform(m_pattern.begin(), m_pattern.end(), m_pattern.begin(), tolower);
    }
    return stack_str_like(m_str, m_pattern);
}

bool stack_str_like(const std::string& m_str, const std::string& m_pattern){
    size_t i = 0;
    std::stack<std::pair<std::string, std::string>>  pattern_stack;
    std::string st_str, st_pattern;
    pattern_stack.push(std::make_pair(m_str, m_pattern));

    while(!pattern_stack.empty()){
        st_str = pattern_stack.top().first;
        st_pattern = pattern_stack.top().second;
        pattern_stack.pop();

        if(st_pattern.length() == 0 && st_str.length() == 0){
            return 1;
        }
        else if(st_pattern[0] == '%' && st_pattern.length() != 0){
            if(st_str.length() != 0){
                for(i = 0; i <= st_str.length(); ++i){
                    pattern_stack.push(std::make_pair(st_str.substr(i, st_str.length() - i), st_pattern.substr(1, st_pattern.length() - 1)));
                }
            }
            else{
                pattern_stack.push(std::make_pair(st_str, st_pattern.substr(1, st_pattern.length() - 1)));
            }
        }
        else if(st_pattern[0] == '_'){
            if(st_str.length() != 0)
                pattern_stack.push(std::make_pair(st_str.substr(1, st_str.length() - 1), st_pattern.substr(1, st_pattern.length() - 1)));
        }
        else if(st_pattern[0] == st_str[0]){
            pattern_stack.push(std::make_pair(st_str.substr(1, st_str.length() - 1), st_pattern.substr(1, st_pattern.length() - 1)));
        }
    }
    return 0;
}

bool Like::match(const StringType& str) const{
    return like(str, pattern);
}
