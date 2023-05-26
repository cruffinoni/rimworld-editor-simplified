//
// Created by toixd on 5/23/2023.
//

#ifndef RIMWORLDEDITOR_META_HPP
#define RIMWORLDEDITOR_META_HPP


#include <map>
#include <any>
#include "../game_base.hpp"
#include "../constructor.hpp"

namespace rimworld::game {
    class Meta : public AbstractGameBase {
    public:
        Meta();
        ~Meta() = default;

        std::string GetPath() override;
        void Visit(const tinyxml2::XMLNode *node) override;
    private:
        std::shared_ptr<Constructor<std::string>> game_version_;
        std::map<std::string, std::pair<std::string, int64_t>> mods_;
    };
}


#endif //RIMWORLDEDITOR_META_HPP
