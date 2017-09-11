//
// Created by Yair on 07-Sep-17.
//

#ifndef BAR_DRINK_H
#define BAR_DRINK_H

#include <string>
#include <iostream>

class Drink {
protected:
    std::string m_drinkName;
public:
    explicit Drink(const std::string &name);
    Drink();
    virtual std::string getName() const { return m_drinkName;};
    virtual std::string prepare() const = 0;
};


#endif //BAR_DRINK_H
