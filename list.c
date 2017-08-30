//
// Created by Yair on 14-Aug-17.
//
#include "list.h"

list* initList(node* head){
    list* tmp;
    tmp = (list*) malloc(sizeof(list));
    if (tmp != NULL) {
        tmp->_head = head ? head : NULL;
        tmp->_last = head ? head : NULL;
        tmp->_length = tmp->_head ? 1 : 0;
        tmp->_sum = tmp->_head ? tmp->_head->value : 0;
    }
    return tmp;
}

node* addNode(list* listHelper, int val){
    node* tmp = (node*) malloc(sizeof(node));
    if (tmp != NULL) {

        tmp->value = val;
        tmp->next = NULL;
        tmp->previous = listHelper->_last;
        if (listHelper->_last)
        {
            listHelper->_last->next = tmp;
        }
        if (!listHelper->_head) {
            listHelper->_head = tmp;
        }
        listHelper->_length++;
        listHelper->_sum += val;
        listHelper->_last = tmp;
    }
    return tmp;
}

void removeNode(node* nodeToRemove, list* listHelper){
    if(nodeToRemove->previous){
        nodeToRemove->previous->next = nodeToRemove->next;
    }
    if (nodeToRemove->next)
    {
        nodeToRemove->next->previous=nodeToRemove->previous;
    }
    listHelper->_length--;
    listHelper->_sum -= nodeToRemove->value;
    if (nodeToRemove == listHelper->_last)
    {
        listHelper->_last = nodeToRemove->previous;
    }
    if(nodeToRemove == listHelper->_head)
    {
        listHelper->_head = nodeToRemove->next;
    }
    free(nodeToRemove);
}

node* getLast(list* listHelper){
    return listHelper->_last;
}

node* getFirst(list* listHelper){
    return listHelper->_head;
}

node* getNext(node* current) {
    return (current->next);
}

node* getPrevious(node* current) {
    return (current->previous);
}

int getVal(node* current) {
    return current->value;
}

double getAvg(list* listHelper) {
    return ((double) listHelper->_sum / (double) listHelper->_length);
}

void deleteList(list* listHelper) {
    node* tmp = listHelper->_head;
    while (tmp)
    {
        node* next = tmp->next;
        free(tmp);
        tmp = next;
    }
}