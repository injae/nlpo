#ifndef __NLPO_VALUE_H__
#define __NLPO_VALUE_H__

#include <variant>
#include <string>
#include <fmt/format.h>
#include <type_traits>
#include <cctype>
#include <sstream>


namespace nlpo
{
    template<class T> struct always_false : std::false_type {};
    template<class... T> struct overloaded : T... { using T::operator()...; };
    template<class... T> overloaded(T...) -> overloaded<T...>;
    inline bool str_to_bool(const std::string& str) { return str == "true" ? true : false; }
    inline bool is_boolean(const std::string& str) {
        return str == "true" || str == "false" ? true : false;
    }
    inline bool is_float(const std::string& str) {
        std::istringstream iss(str); float f;
        iss >> std::noskipws >> f; 
        return iss.eof() && !iss.fail(); 
    }

    inline bool is_digit(const std::string &str) { return str.find_first_not_of("0123456789") == std::string::npos; }

    class value {
    public:
        using type = std::variant<std::string, bool, int, float>;
        template<typename T> value(T v): data_(v) {};
        template<typename T> T get() { return std::get<T>(data_); }
        static value from_str(const std::string& str) {
                 if(is_boolean(str)) return str_to_bool(str);
            else if(is_digit(str))   return stoi(str);
            else if(is_float(str))   return stof(str);
            else return str;
        }
    private:
        type data_;
    };
}


#endif
