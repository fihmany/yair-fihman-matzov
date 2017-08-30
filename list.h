#ifndef MATZOV_LIST_H
#define MATZOV_LIST_H

#include <stdio.h>
#include <malloc.h>

typedef struct nodes{
    int value;
    struct nodes* next;
    struct nodes* previous;
}node;

typedef struct List{
    node* _head;
    node* _last;
    int _length;
    int _sum;
    
}list;


///
/// \param head - pointer to the head of the list (can be null)
/// \return pointer to the list "manger"
list* initList(node* head);

/// adding node to list
/// \param val - value to add
node* addNode(list* listHelper, int val);

/// removes
/// \param nodeToRemove
void removeNode(node* nodeToRemove, list* listHelper);

/// return the last element of the list
/// \param listHelper
/// \return  the last element
node* getLast(list* listHelper);

/// return the first element of the list
/// \param listHelper
/// \return the first element
node* getFirst(list* listHelper);

/// returns the next node
/// \param current node
/// \return next node
node* getNext(node* current);

/// returns the previous node
/// \param current node
/// \return previous node
node* getPrevious(node* current);

///
/// \param current node
/// \return the value of the node
int getVal(node* current);

///
/// \param listHelper
/// \return return the avg of the list
double getAvg(list* listHelper);

/// delete the list and free the memory
/// \param listHelper
void deleteList(list* listHelper);

#endif //MATZOV_LIST_H
