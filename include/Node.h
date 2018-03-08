#ifndef NODE
#define NODE

#include "Neighbor.h"

struct Node{
    Neighbor* first;
    int neighbors;
    bool processed;
    char text;

    Node(){
        this->first = nullptr;
        this->neighbors = 0;
        this->processed = false;
        this->text = ' ';
    }
};

#endif
