#include "nlpo/option.h"
#include <iostream>
#include <assert.h>

namespace nlpo
{
    bool Option::isa(const std::string& argument) {
        if(argument == name_) return true;
        if(argument == abbr_ && argument != "") return true;
        return false;
    }
    
    void Option::print(size_t space) {
        if(visible_ == false) return;
        std::string text;
        std::cout.width(space);
        std::cout << "";
        assert(name_ != "");
        if(abbr_ != "" ) { text += abbr_ + " [ " + name_ + " ] ";  }
        else             { text += name_; }
        std::cout.setf(std::ios::left);
        std::cout.width(29);
        std::cout << text;
        std::cout << " = " << desc_ << std::endl;;
    }
    
    void Option::run() {
        
    }
    
    Option& Option::visible(bool is_visible) {
        visible_ = is_visible;
        return *this; 
    }
    
    Option& Option::name(const std::string& name) {
        name_ = name;     
        return *this;
    }
    
    Option& Option::description(const std::string& desc) {
        desc_ = desc;     
        return *this;
    }
    
    Option& Option::abbreviation(const std::string& abbr) {
        abbr_ = abbr;     
        return *this;
    }
    
    Option& Option::call_back(std::function<void()>&& func) {
       call_backs_.emplace_back(std::move(func));
       return *this;
    }
}
