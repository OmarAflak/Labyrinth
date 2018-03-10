#include <iostream>
#include <fstream>
#include <vector>

#include "../include/algorithm.h"

int main(int argc, char const *argv[]) {
	std::vector<std::vector<Node> > nodes, path;
	std::vector<std::string> labyrinth;
	const char* filepath = "./data/labyrinth3";

	if(readLabyrinth(filepath, nodes, labyrinth)){
		Point in(0, 0);
		Point out(nodes[0].size()-1, nodes.size()-1);

		BFS(nodes, in, out);
		if(findPath(nodes, path, in, out)){
			print(path, labyrinth, std::cout);
		}
		freeMemory(nodes);
	}
	else{
		std::cerr << "Could not read " << filepath << std::endl;
		return 1;
	}
	return 0;
}
