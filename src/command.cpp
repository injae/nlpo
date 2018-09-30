#include "nlpo/command.h"

namespace nlpo
{
    Command& Command::desc(std::string_view description) {
        desc_ = description;
        return *this;
    }

    Command& Command::call_back(std::function<void()>&& func) {
        call_backs_.emplace_back(std::move(func));
        return *this;
    }

    void Command::run() {
        for(auto& func : call_backs_) func();
    }

    std::string Command::make_description() {
        return name_ + " :\t\t\t" + desc_ + "\n";
    }
}
