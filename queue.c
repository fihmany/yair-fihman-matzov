//
// Created by Yair on 14-Aug-17.
//

#include "queue.h"

queue* initQueue(queue_node* node){
    queue* tmp = (queue*) malloc(sizeof(queue));
    if (tmp !=  NULL){
        tmp->_len = node?1:0;
        tmp->_top = node;
        tmp->_last = node;
    }
    return tmp;
}

queue_node* push(int val, queue* queueHelper){
    queue_node* tmp = (queue_node*) malloc(sizeof(queue_node));
    if (tmp != NULL) {
        tmp->_val = val;
        tmp->_next = NULL;
        if (!queueHelper->_top) {
            queueHelper->_top = tmp;
        }
        if (queueHelper->_last) {
            queueHelper->_last->_next = tmp;
        }
        queueHelper->_last = tmp;
        queueHelper->_len++;
    }
    return tmp;
}

int pop(queue* queueHelper) {
    queue_node* oldTop = queueHelper->_top;
    queueHelper->_top = oldTop->_next;
    int value = oldTop->_val;
    free(oldTop);
    queueHelper->_len--;
    return value;
}

int queueLen(queue* queueHelper) {
    return queueHelper->_len;
}

int peek(queue* queueHelper){
    return (queueHelper->_top->_val);
}

void deleteQueue(queue* queueHelper){
    queue_node* tmp = queueHelper->_top;
    while (tmp){
        queue_node* next = tmp->_next;
        free(tmp);
        tmp = next;
    }
}