#ifndef __NLPO_ARGS_HPP__
#define __NLPO_ARGS_HPP__

#include<vector>
#include<list>
#include<string>

namespace nlpo
{
    class Args 
    {
    public:
        Args(int argc, char* argv[]);
        inline std::list<std::string>& get() { return args_; }
        inline bool empty() { return args_.empty(); }
        inline void clear() { args_.clear(); }
        const std::string& name() { return name_; }
        std::string pop();
    private:
        std::string name_;
        std::list<std::string> args_; 
    };
}

#endif