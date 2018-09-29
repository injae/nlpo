#include "nlpo/option.h"
#include "nlpo/app.h"
#include <iostream>

namespace nlpo
{
    Option& Option::abbr(const char* abbreviation) {
        abbr_ = abbreviation; 
        owner_->options_[ ("-" + abbr_) ] = shared_from_this();
        return *this;
    }

    Option& Option::desc(const char * description) {
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
}
