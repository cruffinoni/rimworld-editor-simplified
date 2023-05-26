//
// Created by toixd on 5/23/2023.
//

#ifndef RIMWORLDEDITOR_XML_ABSTRACT_LOADER_HPP
#define RIMWORLDEDITOR_XML_ABSTRACT_LOADER_HPP

#include <string>
#include <memory>
#include "tinyxml2.h"

namespace rimworld::xml {
    class AbstractLoader {
    public:
        AbstractLoader(const std::string& path);
        virtual ~AbstractLoader();
        virtual std::shared_ptr<tinyxml2::XMLDocument> get_document();

    private:
        std::shared_ptr<tinyxml2::XMLDocument> document_;
    };
}

#endif //RIMWORLDEDITOR_XML_ABSTRACT_LOADER_HPP
