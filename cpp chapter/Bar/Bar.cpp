//
// Created by Yair on 07-Sep-17.
//

#include "Bar.h"

Bar::Bar(int shelfSize) {
    m_shelfSize = shelfSize;
    m_stock = new Drink*[m_shelfSize];
    m_lastDrink = nullptr;
    if (m_shelfSize >= 11)
    {
        addToStock();
    }
}

void Bar::addToStock() {
    m_stock[0] = new Beer("Heineken");
    m_stock[1] = new Beer("Carlsberg");
    m_stock[2] = new Beer("Maccabi");
    m_stock[3] = new Beer("Tuborg");
    m_stock[4] = new CarmelEmeraldRiesling(1986);
    m_stock[5] = new GolanSmadar(1989);
    m_stock[6] = new YardenChardonnay(1997);
    m_stock[7] = new Chianti(1997);
    m_stock[8] = new YardenHermonRed(1994);
    m_stock[9] = new YardenVabernetSauvignon(1977);
    m_stock[10] = new ChadeauMargot(1977);
}

Bar::~Bar() {
    /*for (int i = 0; i < m_shelfSize; ++i) {
        delete(m_stock[i]);
    }*/
    delete[] m_stock;

}

void Bar::serve() {
    std::string user_input;
    int choice;
    do
    {
        std::cout << "What can I get you, sir?(0 - list options)" << std::endl;
        std::cin >> user_input;
        choice = std::stoi(user_input);
        switch (choice)
        {
            case 0:
                printList();
                break;
            case 99:
                if (m_lastDrink != nullptr)
                {
                    std::cout << m_lastDrink->prepare() << std::endl;
                }
                else
                {
                    std::cout << "You haven't ordered anything yet." << std::endl;
                }
                break;
            default:
                std::cout << "One " << m_stock[choice - 1]->getName() << " on the way." << std::endl;
                m_lastDrink = m_stock[choice - 1];
                break;
        }
    }while (choice != 100 && choice >= 0 && choice < 100);
    std::cout << "Bar is closed. Good night!" << std::endl;

}

void Bar::printList() {
    std::cout << "(0) list options " << std::endl;
    for (int i = 0; i < m_shelfSize; ++i) {
        std::cout << "(" << i + 1 << ") "<< m_stock[i]->getName() << std::endl;
    }
    std::cout << "(99) How did you prepare my last drink? " << std::endl;
    std::cout << "(100) Leave the bar" << std::endl;

}
