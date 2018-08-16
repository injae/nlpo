#include "nlpo/program.h"
#include <assert.h>
#include <iostream>

namespace nlpo
{
    Program::Program(Args&& args) : args_(std::move(args)) { }
    void Program::run() {
        std::string arg;
        do {
            if(args_.empty())   arg = " ";
            else                arg = args_.pop(); 
            for(auto& group : options_) {
                for(auto& [name, option] : group.second.options()) {
                    if(option.isa(arg)) {
                        for(auto call_back : option.call_back()) call_back();
                        goto find; 
                    }
                }
            }
            std::cerr <<"Error: " << arg << ": command & option not found: " << std::endl;
            return;
            
            find:;
            
       } while(!args_.empty());
        
    }
    
    void Program::help() {
        for(auto& [name, option] : options_) {
           option.print();
        }
    }
    
    OptionGroup& Program::operator[] (const std::string& option) { 
        if(options_.find(option) == options_.end()) options_[option].name(option);
        return options_[option]; 
    }
    
    void Program::add(OptionGroup&& group) {
        auto name = group.name();
        options_.emplace(std::move(name), std::move(group));
    }
}