//
// Created by Yair on 14-Aug-17.
//

#include "list.h"
#include "queue.h"

int mainForListAndQueue(){
    ///list
    list* listA = initList(NULL);
    addNode(listA, 15);
    addNode(listA, 7);
    addNode(listA, 9);
    addNode(listA, 17);
    node* a = addNode(listA, 75);
    removeNode(a, listA);
    printf("first node: %d last node: %d avg: %f \n", getVal(getFirst(listA)), getVal(getLast(listA)), getAvg(listA));
    deleteList(listA);
    free(listA);
    ///end of list

    ///queue
    queue* queueA = initQueue(NULL);
    push(5, queueA);
    push(7, queueA);
    push(8, queueA);
    push(2, queueA);
    push(15, queueA);
    printf("pop: %d ", pop(queueA));
    printf("len: %d ", queueLen(queueA));
    printf("peek: %d ", peek(queueA));
    printf("len: %d\n", queueLen(queueA));
    deleteQueue(queueA);
    free(queueA);
    ///end of queue
    return 0;
}