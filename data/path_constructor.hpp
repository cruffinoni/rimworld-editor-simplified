//
// Created by toixd on 5/23/2023.
//

#ifndef RIMWORLDEDITOR_PATH_CONSTRUCTOR_HPP
#define RIMWORLDEDITOR_PATH_CONSTRUCTOR_HPP


#include <string>
#include <vector>
#include "tinyxml2.h"

namespace rimworld::game {
    class PathConstructor {
    public:
        PathConstructor() = default;
        explicit PathConstructor(const std::string &path);
        ~PathConstructor() = default;
        PathConstructor(const PathConstructor &rhs);

        [[nodiscard]] bool Match(const std::string &rhs) const;

        void Append(const std::string &node);
        void RemoveLastNode();
        [[nodiscard]] std::string GetPath() const;
    private:
        static std::vector<std::string> split(const std::string &s, char delim);
        static bool arrayMatch(const std::string &l,const std::string &r);

        std::string path_;
        int current_idx_ = 0;
    };
}


#endif //RIMWORLDEDITOR_PATH_CONSTRUCTOR_HPP
