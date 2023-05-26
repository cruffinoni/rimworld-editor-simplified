//
// Created by toixd on 5/23/2023.
//

#include "meta.hpp"

std::string rimworld::game::Meta::GetPath() {
    return "meta";
}

void rimworld::game::Meta::Visit(const tinyxml2::XMLNode *node) {
    printf("Node: %s: %p\n", node->Value(), node->GetDocument());
    if (node->NoChildren()) {
        printf("No children detected but some are expected\n");
        throw std::exception();
    }
    auto c = node->FirstChild();
//    printf("??? %p\n", c->GetDocument());
    while (c != nullptr) {
        printf("Value of node: '%s' : %p\n", c->Value(), c->GetDocument());
        auto it = members_.find(c->Value());
        if (it != members_.end()) {
            it->second(c);
        }
        c = c->NextSibling();
    }
}

rimworld::game::Meta::Meta(): game_version_ (std::make_shared<Constructor<std::string>>("Unknown")) {
    this->members_ = {
            {"gameVersion", [this](const tinyxml2::XMLNode* node) -> void {
                printf("gameVersion called: %s : %p\n",node->FirstChild()->Value(), node->GetDocument());
                this->game_version_->Construct(node->FirstChild()->Value());
            }},
            {"modsSteamIds", [this](const tinyxml2::XMLNode* node) -> void {
                printf("modsSteamIds called\n");
            }}
    };
}

