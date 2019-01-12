#include "nlpo/option.h"
#include "nlpo/app.h"
#include <iostream>
#include <fmt/format.h>

using namespace fmt::literals;

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

    Option& Option::args(const std::string& arguments) {
        args_ = arguments;
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
        if(abbr_ == "") {
            auto front = "{:<3}--{} {}"_format("",name_, args_);
            auto end = ":{0}"_format(desc_);
            return "{:<35}{:<20}\n"_format(front,end);
        }
        else  {
            auto front = "{:<3}--{} [-{}] {}"_format("",name_,abbr_,args_);
            auto end = ":{0}"_format(desc_);
            return "{:<35}{:<20}\n"_format(front,end);
        }
    }
}
