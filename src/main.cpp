#include <iostream>
#include <fstream>
#include <vector>

#include "../include/utils.h"
#include "../include/algorithm.h"

int main(int argc, char const *argv[]) {
	std::vector<std::vector<Node> > nodes;
	std::vector<std::string> labyrinth;
	if(read_labyrinth("data/labyrinth3", nodes, labyrinth)){
		BFS(nodes, 0, 0);
		print(nodes, labyrinth, std::cout);
		free_memory(nodes);
	}
	return 0;
}
