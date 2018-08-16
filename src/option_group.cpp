#include "nlpo/option_group.h"
#include <iostream>
#include <iomanip>

namespace nlpo
{
    OptionGroup::OptionGroup(OptionGroup&& other) {
        name_ = move(other.name_);
        options_ = move(other.options_);
        visible_ = other.visible_;
    }
    
    Option& OptionGroup::operator[] (const std::string& option) { 
        if(options_.find(option) == options_.end()) options_[option].name(option);
        return options_[option]; 
    }
    
    void OptionGroup::print() {
        if(visible_ == false) return;
        std::cout << name_ << std::endl;
        for(auto& [name, option] : options_) {
            option.print(3);
        }
    }
}
