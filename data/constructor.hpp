//
// Created by toixd on 5/23/2023.
//

#ifndef RIMWORLDEDITOR_CONSTRUCTOR_HPP
#define RIMWORLDEDITOR_CONSTRUCTOR_HPP

#include <string>
#include <functional>
#include <iostream>
#include "../libs/tinyxml2/tinyxml2.h"

namespace rimworld::game {
    template<typename T, typename = std::enable_if_t<std::is_constructible<T>::value>>
    class Constructor {
    public:
        Constructor() = default;
        ~Constructor() = default;
        Constructor(const tinyxml2::XMLNode* node, const std::function<void(const tinyxml2::XMLNode*)> &function) {
            function(node);
        }

        template<typename ...Args, typename = typename std::enable_if_t<std::is_constructible<T, Args...>::value>>
        Constructor(Args &&...args) {
            this->Construct(args...);
        }

        template<typename ...Args, typename = typename std::enable_if_t<std::is_constructible<T, Args...>::value>>
        void Construct(Args &&...args) {
            type_ = std::make_shared<T>(std::forward<Args>(args)...);
            printf("Construct called here\n");
        }

        std::shared_ptr<T> GetConstruct() const {
            return this->type_;
        }
    private:
        std::shared_ptr<T> type_;
    };
}

#endif //RIMWORLDEDITOR_CONSTRUCTOR_HPP
