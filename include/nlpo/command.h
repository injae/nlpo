#ifndef __NLPO_COMMAND_H__
#define __NLPO_COMMAND_H__

#include <string>
#include <memory>
#include <vector>
#include "nlpo/arg.h"

namespace nlpo
{
    class App;
    class Command : public std::enable_shared_from_this<Command>
    {
    public:
        Command(std::string name) : name_(name) {}
        void regist(App* app) { owner_ = app;}
        Command& desc(const std::string& description);
        Command& args(const std::string& description);
        Command& call_back(arg::hook::None&& func);
        Command& call_back(arg::hook::One func  , std::string desc = "{arg}");
        Command& call_back(arg::hook::Multi func, std::string desc = "{...args}");
        std::string make_description();
        Command& is_show(bool show) { is_show_ = !show; return *this;}
        void run();
    private:
        bool is_show_ = false;
        std::string name_;
        std::string desc_;
        std::string args_;
        App* owner_;
        std::vector<arg::hook::None> call_backs_;
    };
}

#endif
