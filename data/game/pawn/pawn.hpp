//
// Created by toixd on 5/23/2023.
//

#ifndef RIMWORLDEDITOR_PAWN_HPP
#define RIMWORLDEDITOR_PAWN_HPP


#include <memory>
#include "../../game_base.hpp"

namespace rimworld::game {
    class Pawn {
    public:
        Pawn();

    private:
        shared_xml_node node_;
    };
}


#endif //RIMWORLDEDITOR_PAWN_HPP
