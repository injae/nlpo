#ifndef __NLPO__OPTION_H__
#define __NLPO__OPTION_H__

#include <string>
#include <string_view>
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
        Option& abbr(std::string_view abbreviation);
        Option& desc(std::string_view description);
        Option& call_back(std::function<void()>&& func);
        std::string make_description();
        void run(); 
    private:
        std::string name_;
        std::string desc_;
        std::string abbr_;
        App* owner_;
        std::vector<std::function<void()>> call_backs_;
    };
}

#endif
