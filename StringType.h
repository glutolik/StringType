#include <cstring>
#include <regex>
#include <iostream>

class StringType{
private:
    const char* m_str;
    size_t m_size;
public:
    StringType(const char* str, size_t size) : m_str(str),
    m_size(size)
    {}
    StringType(const char* str) : StringType(str, strlen(str))
    {}
    size_t size() const { return m_size; }
    const char* data() { return m_str; }

    size_t get_size() const{
        return m_size;
    }
    const char* get_str() const{
        return m_str;
    }
};

bool like( const StringType& str, const StringType& pattern, char escape = '\\', bool ignorecase = false);
//    size_t n = str.get_size();
//
//    std::string regex_pattern;
//    for(size_t i = 0; i < n; ++i){
//        if(str.get_str()[i] == '_'){
//            regex_pattern += "[a-z]^*";
//        }
//        else if(str.get_str()[i] == '%'){
//            regex_pattern += "[_[:alnum:]]*";
//        }
//        else{
//            regex_pattern += str.get_str()[i];
//        }
//        //std::cout << regex_pattern << std::endl;
//    }
//    //regex_pattern += ")";
//    std::cout << regex_pattern << std::endl;
//    const char* r_pattern = regex_pattern.c_str();
//
//    std::regex_constants::match_flag_type flags;
//    if(ignorecase)
//        flags = std::regex_constants::icase;
//    else
//        flags = std::regex_constants::match_default;
//
//    bool comp_res = false;
//
//    try{
//        std::regex reg(r_pattern, std::regex_constants::extended);
//        comp_res = regex_match(pattern.get_str(), reg, flags);
//    }
//    catch(std::regex_error e) {
//		std::cout << "what: " << e.what() << " code: " << e.code() << std::endl;
//	}
//    return comp_res;
//}
