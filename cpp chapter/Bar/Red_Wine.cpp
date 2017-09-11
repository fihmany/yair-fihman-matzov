//
// Created by Yair on 11-Sep-17.
//

#include "Red_Wine.h"

Red_Wine::Red_Wine(int year, const std::string &name) : Wine(year, name) {
}

std::string Red_Wine::prepare() const {
    return (std::string("Pour in room temperature into a wine glass and serve."));
}
