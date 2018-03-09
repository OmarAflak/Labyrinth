#ifndef UTILS
#define UTILS

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Node.h"
#include "Point.h"

bool read_file(const char* filename, std::vector<std::string> &lines);
bool read_labyrinth(const char* filename, std::vector<std::vector<Node> > &nodes, std::vector<std::string> &labyrinth);
void print(const std::vector<std::vector<Node> > &nodes, const std::vector<std::string> &labyrinth, std::ostream &os);
void reset(std::vector<std::vector<Node> > &nodes);
void free_memory(const std::vector<std::vector<Node> > &nodes);

#endif
