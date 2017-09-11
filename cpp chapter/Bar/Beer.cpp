//
// Created by Yair on 11-Sep-17.
//

#include "Beer.h"

Beer::Beer(const std::string &name) : Drink(name) {

}

std::string Beer::prepare() const {
    return (std::string("Well, all you need to do is pour it into a glass and serve."));
}
