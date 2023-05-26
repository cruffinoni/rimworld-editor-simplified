#include <iostream>
#include "libs/tinyxml2/tinyxml2.h"
#include "data/loader.hpp"
#include "data/path_constructor.hpp"

int main() {
//    tinyxml2::XMLDocument doc;
//    auto err = doc.LoadFile("../sample/small.rws");
//    if (err != tinyxml2::XML_SUCCESS) {
//        printf("Err: %d", err);
//        return 1;
//    }
//    auto c = doc.FirstChild();
//    while (c != nullptr) {
//        if (c->ToDeclaration() != nullptr) {
//            c = c->NextSibling();
//            continue;
//        }
//        printf("Node: %s\n", c->Value());
//        c = c->NextSibling();
//    }
    rimworld::game::Loader loader("../sample/part.rws");
    loader.ProcessLoader();
    return 0;
}
