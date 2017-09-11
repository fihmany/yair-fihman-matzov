//
// Created by Yair on 11-Sep-17.
//

#include "White_Wine.h"

White_Wine::White_Wine(int year, const std::string &name) : Wine(year, name) {
}

std::string White_Wine::prepare() const {
    return (std::string("Pour cooled into a wine glass and serve."));
}
