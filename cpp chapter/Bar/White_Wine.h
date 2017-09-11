//
// Created by Yair on 11-Sep-17.
//

#ifndef BAR_WHITE_WINE_H
#define BAR_WHITE_WINE_H

#include "Wine.h"

class White_Wine: public Wine {
public:
    White_Wine(int year, const std::string &name);
    virtual std::string prepare() const;
};


#endif //BAR_WHITE_WINE_H
