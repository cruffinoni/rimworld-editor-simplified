//
// Created by toixd on 5/23/2023.
//

#ifndef RIMWORLDEDITOR_GAME_LOADER_HPP
#define RIMWORLDEDITOR_GAME_LOADER_HPP

#include "factory.hpp"
#include "../xml/abstract_loader.hpp"
#include "path_constructor.hpp"

namespace rimworld::game {
    class Loader {
    public:
        Loader() = delete;
        Loader(const std::string &path);
        void ProcessLoader(tinyxml2::XMLNode *node = nullptr);

    private:

        game::Factory<game::AbstractGameBase> factory_;
        rimworld::xml::AbstractLoader reader_;
        PathConstructor pc_;
    };
}

#endif //RIMWORLDEDITOR_GAME_LOADER_HPP
