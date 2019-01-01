#include "nlpo/option.h"
#include "nlpo/app.h"
#include <iostream>

namespace nlpo
{
    Option& Option::abbr(const std::string& abbreviation) {
        abbr_ = abbreviation; 
        owner_->options_[ ("-" + abbr_) ] = shared_from_this();
        return *this;
    }

    Option& Option::desc(const std::string& description) {
        desc_ = description;
        return *this;
    }

    Option& Option::call_back(std::function<void()>&& func) {
        call_backs_.emplace_back(std::move(func));
        return *this;
    }

    void Option::run() {
        for(auto& func : call_backs_) func();
    }

    std::string Option::make_description() {
        if(is_show_)  return "";
        is_show_ = true;
        if(abbr_ == "")
           return "   --" + name_ + "\t\t\t:" + desc_ + "\n";
        else 
           return "   --" + name_ + "[ -"+abbr_+" ]\t\t:" + desc_ + "\n";
    }
}
