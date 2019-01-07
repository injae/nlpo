#include "nlpo/command.h"
#include <fmt/format.h>

using namespace fmt::literals;

namespace nlpo
{
    Command& Command::desc(const std::string& description) {
        desc_ = description;
        return *this;
    }

    Command& Command::call_back(std::function<void()>&& func) {
        call_backs_.emplace_back(std::move(func));
        return *this;
    }

    Command& Command::args_desc(const std::string& description) {
        args_desc_ = description;
        return *this;
    }

    void Command::run() {
        for(auto& func : call_backs_) func();
    }

    std::string Command::make_description() {
        if(is_show_)  return "";
        is_show_ = true;
        auto front = "{:<3}{} {}"_format("",name_,args_desc_);
        auto end = ":{0}"_format(desc_);
        return "{:<30}{:<20}\n"_format(front,end);
    }
}
