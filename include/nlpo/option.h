#ifndef __NLPO_OPTION_HPP__
#define __NLPO_OPTION_HPP__

#include <string>
#include <vector>
#include <functional>

namespace nlpo
{
    class Option 
    {
    public:
        bool isa(const std::string& argument);
        void print(size_t space = 0);
        void run();
    public:
        Option& name(const std::string& name);        
        Option& description(const std::string& desc);
        Option& abbreviation(const std::string& abbr);
        Option& call_back(std::function<void()>&& func);
        Option& visible(bool is_visible);
        
        const auto& name()        { return name_; }
        const auto& call_back()   { return call_backs_; }
        const auto& description() { return desc_; }
        const auto& abbreviation(){ return abbr_; }
    private:
        std::string name_;
        std::string desc_;
        std::string abbr_;
        bool visible_ = true;
        std::vector<std::function<void()>> call_backs_;
    };
}

#endif