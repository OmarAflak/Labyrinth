#ifndef UTILS
#define UTILS

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Node.h"
#include "Point.h"

static const char IN = 'I';
static const char OUT = 'O';
static const char MARKED = 'x';
static const char UNMARKED = ' ';

bool readFile(const char* filename, std::vector<std::string> &lines);
bool readLabyrinth(const char* filename, std::vector<std::vector<Node> > &nodes, std::vector<std::string> &labyrinth);
void print(const std::vector<std::vector<Node> > &nodes, const std::vector<std::string> &labyrinth, std::ostream &os);
void apply(std::vector<std::vector<Node> > &nodes, void (*change)(Node& node));
void unprocess(Node& node);
void unmark(Node& node);
void freeMemory(const std::vector<std::vector<Node> > &nodes);

#endif
