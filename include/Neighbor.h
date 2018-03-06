#ifndef NEIGHBOR
#define NEIGHBOR

struct Neighbor{
	int i;
	int j;
	Neighbor* next;

	Neighbor(){
		this->next = NULL;
	}

	Neighbor(int i, int j, Neighbor* next){
		this->i = i;
		this->j = j;
		this->next = next;
	}
};

#endif
