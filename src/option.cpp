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

    Option& Option::call_back(arg::hook::None&& func) {
        call_backs_.emplace_back(std::move(func));
        return *this;
    }

    Option& Option::call_back(arg::hook::One func, std::string desc) {
        args_ = desc;
        call_backs_.push_back([=](){func(owner_->require_arg());});
        return *this;
    }

    Option& Option::call_back(arg::hook::Multi func, std::string desc) {
        args_ = desc;
        call_backs_.push_back([=](){func(owner_->require_args());});
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

    //    Option& Group::add_option(const std::string& name) {
    //        auto opt = "--" + name;
    //        auto option = std::make_shared<Option>(name);
    //        option->regist(owner_);
    //        options_[opt] = option;
    //        return *option;
    //    }
    //
    //    Group& Group::default_option(const std::string& name) {
    //        
    //        return *this;
    //    }
    //
    //    std::shared_ptr<Option> Group::call(const std::string& arg) {
    //        if(auto opt = options_.find(arg); !(opt == options_.end())) {
    //            return opt->second;
    //        }
    //
    //        return nullptr;
    //    }
}
