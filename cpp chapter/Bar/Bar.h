//
// Created by Yair on 07-Sep-17.
//

#ifndef BAR_BAR_H
#define BAR_BAR_H

#include "Drink.h"
#include "Beer.h"
#include "CarmelEmeraldRiesling.h"
#include "ChadeauMargot.h"
#include "Chianti.h"
#include "GolanSmadar.h"
#include "YardenChardonnay.h"
#include "YardenHermonRed.h"
#include "YardenVabernetSauvignon.h"

class Bar {
private:
    int m_shelfSize;
    Drink** m_stock;
    Drink* m_lastDrink;
    void printList();
public:
    explicit Bar(int shelfSize);
    void addToStock();
    void serve();
    ~Bar();
};


#endif //BAR_BAR_H
