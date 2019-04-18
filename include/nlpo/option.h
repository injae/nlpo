#ifndef __NLPO__OPTION_H__
#define __NLPO__OPTION_H__

#include <string>
#include <memory>
#include <functional>

namespace nlpo
{
    class App;
    class Option : public std::enable_shared_from_this<Option>
    {
    public:
        using ptr = std::shared_ptr<Option>;
        ptr get_ptr() { return shared_from_this(); }
        Option(const std::string& name) : name_(name) {}
        void regist(App *app) { owner_ = app; }
        Option& abbr(const std::string& abbreviation);
        Option& desc(const std::string& description);
        Option& args(const std::string& arguments);
        Option& call_back(std::function<void()>&& func);
        void is_show(bool show) { is_show_ = show; }
        std::string make_description();
        void run(); 
    private:
        bool is_show_ = false;
        std::string name_;
        std::string desc_;
        std::string abbr_;
        std::string args_;
        App* owner_;
        std::vector<std::function<void()>> call_backs_;
    };
}

#endif
