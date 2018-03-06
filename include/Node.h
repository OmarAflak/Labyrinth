#ifndef NODE
#define NODE

#include "Neighbor.h"

struct Node{
	int neighbors;
	Neighbor* first;
	bool processed;

	Node(){
		this->neighbors = 0;
		this->first = NULL;
		this->processed = false;
	}
};

#endif
