#ifndef __NLPO_OPTION_GROUP_HPP__
#define __NLPO_OPTION_GROUP_HPP__

#include <string>
#include <map>
#include "nlpo/option.h"

namespace nlpo
{
    class OptionGroup
    {
    public:
        OptionGroup(const std::string& name) : name_(name) {}
        OptionGroup() : name_() {}
        OptionGroup(OptionGroup&& other);
        Option& operator[] (const std::string& option);
        
        void print();
        
        std::map<std::string, Option>& options() { return options_; }
        std::string& name() { return name_; }
        void name(const std::string& name) { name_ = name; }
        void visible(bool is_visible) { visible_ = is_visible; }
    private:
        std::string name_;
        bool visible_ = true;
        std::map<std::string, Option> options_;
    };
}

#endif
