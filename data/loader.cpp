//
// Created by toixd on 5/23/2023.
//

#include "loader.hpp"
#include "./game/meta.hpp"

rimworld::game::Loader::Loader(const std::string &path) : reader_(path), factory_(Meta()) {
}

void rimworld::game::Loader::ProcessLoader(tinyxml2::XMLNode *node) {
    tinyxml2::XMLNode *n = node;
    printf("N: %p\n", n);
    if (node == nullptr) {
        /*
         * Skip the first child (declaration)
         * Then skip the "savegame" layer, there is only one in the save game files
        */
        n = reader_.get_document()->FirstChild()->NextSibling()->FirstChild();
    }
    printf("=> %p & %p\n", reader_.get_document()->FirstChild()->GetDocument(), reader_.get_document()->GetDocument());
    while (n != nullptr) {
        this->pc_.Append(n->Value());
        //printf("PC: '%s'\n", this->pc_.GetPath().c_str());
        auto elem = this->factory_.GetElement(pc_.GetPath());
        if (elem != nullptr) {
            elem->Visit(n);
        }
        auto fc = n->FirstChild();
        if (fc != nullptr && fc->ToText() == nullptr) {
            this->ProcessLoader(fc);
        }
        n = n->NextSibling();
        this->pc_.RemoveLastNode();
    }
    printf("=>> %p & %p\n", reader_.get_document()->FirstChild()->GetDocument(), reader_.get_document()->GetDocument());
}