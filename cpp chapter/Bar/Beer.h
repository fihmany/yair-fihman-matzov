//
// Created by Yair on 11-Sep-17.
//

#ifndef BAR_BEER_H
#define BAR_BEER_H

#include "Drink.h"
#include <string>
#include <iostream>

class Beer: public Drink {
public:
    explicit Beer(const std::string &name);
    virtual std::string getName() const { return m_drinkName;};
    virtual std::string prepare() const;

};


#endif //BAR_BEER_H
