#include "nlpo/args.h"
#include <iostream>
#include <assert.h>

namespace nlpo
{
    Args::Args(int argc, char* argv[]) : name_(argv[0]) {
        for(int i = 1; i < argc; ++i) { 
            args_.emplace_back(std::string{argv[i]}); 
        }
    }
    
    std::string Args::pop() {
        assert(!args_.empty() && "is empty args");
        auto arg = args_.front();
        args_.pop_front();
        return arg;
    }
}