//
// Created by Yair on 11-Sep-17.
//

#ifndef BAR_WINE_H
#define BAR_WINE_H


#include "Drink.h"
#include <string>
#include <iostream>

class Wine: public Drink {
protected:
    int m_year;
public:
    explicit Wine(int year, const std::string &name);
    virtual std::string getName() const { return (m_drinkName + std::string(" (year ") + std::to_string(m_year) + std::string(")"));};
    virtual std::string prepare() const = 0;
};


#endif //BAR_WINE_H
