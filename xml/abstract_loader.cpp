//
// Created by toixd on 5/23/2023.
//

#include "abstract_loader.hpp"

rimworld::xml::AbstractLoader::AbstractLoader(const std::string& path): document_(std::make_unique<tinyxml2::XMLDocument>()) {
    this->document_->LoadFile(path.data());
}


rimworld::xml::AbstractLoader::~AbstractLoader() {
    this->document_->Clear();
}

std::shared_ptr<tinyxml2::XMLDocument> rimworld::xml::AbstractLoader::get_document() {
    return this->document_;
}

