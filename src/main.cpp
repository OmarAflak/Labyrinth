#include <iostream>
#include <fstream>
#include <vector>

#include "../include/utils.h"
#include "../include/algorithm.h"

int main(int argc, char const *argv[]) {
	std::vector<std::vector<Node> > nodes;
	if(read_labyrinth("data/labyrinth2", nodes)){
		DFS(nodes, 0, 0);
		print(nodes, std::cout);
		free_memory(nodes);
	}
	return 0;
}
