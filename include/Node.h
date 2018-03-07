#ifndef NODE
#define NODE

#include "Neighbor.h"

struct Node{
    int neighbors;
    Neighbor* first;
    int flag;

    Node(){
        this->neighbors = 0;
        this->first = NULL;
        this->flag = 0;
    }
};

#endif
