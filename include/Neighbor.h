#ifndef NEIGHBOR
#define NEIGHBOR

#include "Point.h"

struct Neighbor{
	Point pos;
	Neighbor* next;

	Neighbor(){
		this->next = NULL;
	}

	Neighbor(Point pos, Neighbor* next){
		this->pos = pos;
		this->next = next;
	}
};

#endif
