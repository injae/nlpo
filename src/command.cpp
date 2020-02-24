#include "nlpo/command.h"
#include <fmt/format.h>
#include <nlpo/app.h>

using namespace fmt::literals;

namespace nlpo
{
    Command& Command::desc(const std::string& description) {
        desc_ = description;
        return *this;
    }

    Command& Command::call_back(arg::None&& func) {
        call_backs_.emplace_back(std::move(func));
        return *this;
    }

    Command& Command::call_back(arg::One&& func, std::string desc) {
        args_ = desc;
        call_backs_.emplace_back([&](){func(owner_->get_arg());});
        return *this;
    }

    Command& Command::call_back(arg::Multi&& func, std::string desc) {
        args_ = desc;
        call_backs_.emplace_back([&](){func(owner_->args());});
        return *this;
    }

    Command& Command::args(const std::string& description) {
        args_ = description;
        return *this;
    }

    void Command::run() {
        for(auto& func : call_backs_) func();
    }

    std::string Command::make_description() {
        if(is_show_)  return "";
        is_show_ = true;
        auto front = "{:<3}{} {}"_format("",name_,args_);
        auto end = ":{0}"_format(desc_);
        return "{:<35}{:<20}\n"_format(front,end);
    }
}
