//
// Created by toixd on 5/22/2023.
//

#ifndef RIMWORLDEDITOR_FACTORY_HPP
#define RIMWORLDEDITOR_FACTORY_HPP

#include <vector>
#include <memory>
#include <unordered_map>
#include "game_base.hpp"

namespace rimworld::game {
    template<typename T,
            typename = typename std::enable_if<std::is_base_of<AbstractGameBase, T>::value>::type>
    class Factory {
    public:
        template<typename... Args>
        explicit Factory(Args &&... elements) {
            std::vector<std::shared_ptr<T>> elems;
            (elems.emplace_back(std::make_shared<Args>(std::forward<Args>(elements))), ...);
            for (const auto& gd: elems) {
                this->paths_[gd->GetPath()] = gd;
            }
        }

        std::shared_ptr<T> GetElement(const std::string &path) {
            return this->paths_[path];
        }

    private:
        std::unordered_map<std::string, std::shared_ptr<T>> paths_;
    };
}

#endif //RIMWORLDEDITOR_FACTORY_HPP
