#ifndef UTILS
#define UTILS

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Node.h"

bool read_file(const char* filename, std::vector<std::string> &lines);
bool read_labyrinth(const char* filename, std::vector<std::vector<Node> > &nodes);
void print(const std::vector<std::vector<Node> > &nodes, std::ostream &os);
void free_memory(const std::vector<std::vector<Node> > &nodes);

#endif
