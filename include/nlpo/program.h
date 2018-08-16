#ifndef __NLPO_PROGRAM_H__
#define __NLPO_PROGRAM_H__

#include "nlpo/args.h"
#include "nlpo/option_group.h"
#include <map>

namespace nlpo
{
    class Program
    {
    public:
        Program(Args&& args);
        void run();
        void add(OptionGroup&& group);
        OptionGroup& operator[] (const std::string& option);
        void help();
        Args& args() { return args_; }
    private:    
        Args args_; 
        std::map<std::string, OptionGroup> options_;
   };
}


#endif