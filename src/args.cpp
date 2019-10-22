#include "nlpo/args.h"
#include <typeinfo>

namespace nlpo {
    template<typename T>
    args args::arg(std::string_view desc) {
        auto new_arg = arg(std::string_view(typeid(T).name()), desc);
        //args_.insert(new_arg);
    }

}  // nlpo
