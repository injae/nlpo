#ifndef __NLPO__OPTION_H__
#define __NLPO__OPTION_H__

#include <string>
#include <memory>
#include <vector>
#include "nlpo/arg.h"

namespace nlpo
{
    class App;
    class Option : public std::enable_shared_from_this<Option>
    {
    public:
        Option(const std::string& name) : name_(name) {}
        void regist(App *app) { owner_ = app; }
        Option& abbr(const std::string& abbreviation);
        Option& desc(const std::string& description);
        Option& args(const std::string& arguments);
        Option& call_back(arg::hook::None&& func);
        Option& call_back(arg::hook::One func  , std::string desc = "{arg}");
        Option& call_back(arg::hook::Multi func, std::string desc = "{...args}");
        Option& is_show(bool show) { is_show_ = !show; return *this;}
        std::string make_description();
        void run(); 
    private:
        bool is_show_ = false;
        std::string name_;
        std::string desc_;
        std::string abbr_;
        std::string args_;
        App* owner_;
        std::vector<arg::hook::None> call_backs_;
    };
}

#endif
