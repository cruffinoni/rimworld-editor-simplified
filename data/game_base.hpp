//
// Created by toixd on 5/22/2023.
//

#ifndef RIMWORLDEDITOR_GAME_BASE_HPP
#define RIMWORLDEDITOR_GAME_BASE_HPP


#include <string>
#include <memory>
#include <unordered_map>
#include <any>
#include <utility>
#include <functional>
#include "tinyxml2.h"

namespace rimworld::game {
    using shared_xml_node = std::shared_ptr<tinyxml2::XMLNode>;
    class AbstractGameBase {
    public:
        AbstractGameBase() = default;
        virtual ~AbstractGameBase() = default;

        virtual std::string GetPath() = 0;
        virtual void Visit(const tinyxml2::XMLNode *node) = 0;

    protected:
         std::unordered_map<std::string, std::function<void(const tinyxml2::XMLNode*)>> members_;
    };
}


#endif //RIMWORLDEDITOR_GAME_BASE_HPP
