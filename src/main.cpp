#include <iostream>
#include <fstream>
#include <vector>

#include "../include/algorithm.h"

int main(int argc, char const *argv[]) {
	std::vector<std::vector<Node> > nodes, path;
	std::vector<std::string> labyrinth;
	const char* filepath = "./data/labyrinth";

	std::cout << "Processing " << filepath << std::endl << std::endl;
	if(readLabyrinth(filepath, nodes, labyrinth)){
		print(nodes, labyrinth, std::cout);

		Point in, out;
		if(findIO(nodes, in, out)){
			std::cout << std::endl << "DFS :" << std::endl << std::endl;
			DFS(nodes, in, out);
			print(nodes, labyrinth, std::cout);
			if(findPath(nodes, path, in, out)){
				std::cout << std::endl << "Path using DFS :" << std::endl << std::endl;
				print(path, labyrinth, std::cout);
			}
			else{
				std::cout << "Could not find DFS path" << std::endl;
			}

			apply(path, unprocess);
			apply(path, unmark);

			std::cout << std::endl << "BFS :" << std::endl << std::endl;
			BFS(nodes, in, out);
			print(nodes, labyrinth, std::cout);
			if(findPath(nodes, path, in, out)){
				std::cout << std::endl << "Path using BFS :" << std::endl << std::endl;
				print(path, labyrinth, std::cout);
			}
			else{
				std::cout << "Could not find BFS path" << std::endl;
			}

			std::cout << std::endl << "Connexe :" << std::endl << std::endl;
			findConnexe(nodes);
			print(nodes, labyrinth, std::cout);
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
