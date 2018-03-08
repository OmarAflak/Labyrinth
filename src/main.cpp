#include <iostream>
#include <fstream>
#include <vector>

#include "../include/utils.h"
#include "../include/algorithm.h"

int main(int argc, char const *argv[]) {
	std::vector<std::vector<Node> > nodes;
	std::vector<std::string> labyrinth;
	const char* filepath = "./data/labyrinth3";

	if(read_labyrinth(filepath, nodes, labyrinth)){
		BFS(nodes, 0, 0);
		print(nodes, labyrinth, std::cout);
		free_memory(nodes);
	}
	else{
		std::cerr << "Could not read " << filepath << std::endl;
		return 1;
	}
	return 0;
}
