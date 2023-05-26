//
// Created by toixd on 5/23/2023.
//

#include <sstream>
#include "path_constructor.hpp"

rimworld::game::PathConstructor::PathConstructor(const std::string &path): path_(path) {}

void rimworld::game::PathConstructor::Append(const std::string &node) {
    if (node.empty()) {
        printf("Node is empty!\n");
        return;
    }
    if (node == "li") {
        current_idx_++;
        path_ += std::string(">") + node + "[...]";
        return;
    } else {
        current_idx_ = 0;
    }
    if (path_.empty()) {
        path_ = node;
    } else {
        path_ += std::string(">") + node;
    }
}

void rimworld::game::PathConstructor::RemoveLastNode() {
    auto idx = path_.find_last_of('>');
    if (idx != std::string::npos) {
        path_.erase(idx);
    } else {
        path_.erase();
    }
}

std::string rimworld::game::PathConstructor::GetPath() const {
    return path_;
}

rimworld::game::PathConstructor::PathConstructor(const rimworld::game::PathConstructor &rhs) {
    this->path_ = rhs.path_;
    this->current_idx_ = rhs.current_idx_;
}

/*
 * savegame>meta>modIds>li[1]
 * savegame>meta>modIds>li[...]
 */


bool rimworld::game::PathConstructor::arrayMatch(const std::string &l, const std::string &r) {
    if (l.find("...")) {
        return true;
    }
    return l == r;
}

bool rimworld::game::PathConstructor::Match(const std::string &rhs) const {
    auto lparts = PathConstructor::split(path_, '>');
    auto rparts  = PathConstructor::split(rhs, '>');

    if (lparts.size() != rparts.size()) {
        return false;
    }
    for (size_t i = 0, j = lparts.size(); i < j; i++) {
        const auto r = rparts.at(i);
        const auto l = lparts.at(i);
        if (r.find_first_of('[') != std::string::npos) {
            if (!this->arrayMatch(l, r)) {
                return false;
            }
        }
        if (rparts.at(i) != lparts.at(i)) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> rimworld::game::PathConstructor::split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

