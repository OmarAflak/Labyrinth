#ifndef UTILS
#define UTILS

#include <vector>
#include <string>
#include <fstream>

#include "Node.h"

bool read_file(const char* filename, std::vector<std::string> &lines);
bool read_labyrinth(const char* filename, std::vector<std::vector<Node> > &nodes);

#endif
