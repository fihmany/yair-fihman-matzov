//
// Created by Yair on 14-Aug-17.
//
#ifndef MATZOV_QUEUE_H
#define MATZOV_QUEUE_H

#include <stdio.h>
#include <malloc.h>

typedef struct queue_nodes{
    int _val;
    struct queue_nodes* _next;
} queue_node;

typedef struct queues{
    int _len;
    queue_node* _top;
    queue_node* _last;
} queue;

/// initializing queue
/// \param node can be NULL
/// \return pointer to the queue
queue* initQueue(queue_node* node);

///
/// \param val - the value to add
/// \param queueHelper - queue poiner
/// \return pointer to the node added to the queue
queue_node* push(int val, queue* queueHelper);

///
/// \param queueHelper - pointer to the queue
/// \return the value of the first element in the queue
int pop(queue* queueHelper);

///
/// \param queueHelper - pointer to the queue
/// \return the len of the queue
int queueLen(queue* queueHelper);

///
/// \param queueHelper  - pointer to the queue
/// \return the value of the top element of the queue without poping it
int peek(queue* queueHelper);

/// deletes all the queue
/// \param queueHelper - pointer to the queue
void deleteQueue(queue* queueHelper);

#endif //MATZOV_QUEUE_H
