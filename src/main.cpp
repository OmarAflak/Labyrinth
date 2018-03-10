#include <iostream>
#include <fstream>
#include <vector>

#include "../include/algorithm.h"

int main(int argc, char const *argv[]) {
	std::vector<std::vector<Node> > nodes, path;
	std::vector<std::string> labyrinth;
	const char* filepath = "./data/labyrinth3";

	if(readLabyrinth(filepath, nodes, labyrinth)){
		Point in, out;
		if(findIO(nodes, in, out)){
			BFS(nodes, in, out);
			if(findPath(nodes, path, in, out)){
				print(path, labyrinth, std::cout);
			}
			else{
				std::cout << "Could not find path" << std::endl;
			}
		}
		else{
			std::cerr << "Could not find unique I/O pair" << std::endl;
		}
		freeMemory(nodes);
		return 0;
	}
	else{
		std::cerr << "Could not read " << filepath << std::endl;
		return 1;
	}
}
