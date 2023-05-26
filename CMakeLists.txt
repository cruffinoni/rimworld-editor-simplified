cmake_minimum_required(VERSION 3.25)
project(RimworldEditor)

set(CMAKE_CXX_STANDARD 20)

add_executable(RimworldEditor main.cpp xml/loader.cpp xml/loader.hpp data/game_base.hpp data/factory.hpp data/loader.cpp data/loader.hpp xml/abstract_loader.hpp xml/abstract_loader.cpp xml/abstract_loader.cpp data/game/pawn/pawn.cpp data/game/pawn/pawn.hpp data/game/pawn/pawn.hpp data/game/meta.cpp data/game/meta.hpp data/constructor.hpp data/path_constructor.cpp data/path_constructor.hpp data/matcher/abstract_matcher.hpp xml/abstract_writer.cpp xml/abstract_writer.hpp)
add_subdirectory(libs/tinyxml2)
target_link_libraries(RimworldEditor PRIVATE tinyxml2::tinyxml2)
