//
// Created by toixd on 5/21/2023.
//

#ifndef RIMWORLDEDITOR_XML_LOADER_HPP
#define RIMWORLDEDITOR_XML_LOADER_HPP

#include <string>
#include <memory>
#include "tinyxml2.h"
#include "abstract_loader.hpp"

namespace rimworld::xml {
    class Loader : public AbstractLoader {
        Loader(const std::string& path);
    };
}


#endif //RIMWORLDEDITOR_XML_LOADER_HPP
