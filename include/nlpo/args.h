#ifndef __NLPO_ARGS_H__
#define __NLPO_ARGS_H__

#include "value.hpp"
#include <list>
#include <string_view>
#include <optional>

namespace nlpo {

    class arg {
    public:
        arg(std::string_view& type, std::string_view& desc) : type_(type), desc_(desc) {}
    private:
        std::optional<value> value_ = std::nullopt;
        std::string_view type_;
        std::string_view desc_;
    };

    class args {
    public:
        template<typename T>
        args arg(std::string_view desc);

    private:
        std::list<nlpo::arg> args_;
    };
}


#endif
