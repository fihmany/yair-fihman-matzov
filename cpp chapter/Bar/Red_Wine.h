//
// Created by Yair on 11-Sep-17.
//

#ifndef BAR_RED_WINE_H
#define BAR_RED_WINE_H

#include "Wine.h"

class Red_Wine : public Wine {
public:
    Red_Wine(int year, const std::string &name);
    virtual std::string prepare() const;
};


#endif //BAR_RED_WINE_H
