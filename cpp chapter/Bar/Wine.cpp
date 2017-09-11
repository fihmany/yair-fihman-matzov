//
// Created by Yair on 11-Sep-17.
//

#include "Wine.h"

Wine::Wine(const int year,const std::string &name) : Drink(name) {
    m_year = year;
}
