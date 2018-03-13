#ifndef ALGORITHM
#define ALGORITHM

#include <vector>
#include <queue>
#include <stack>

#include "utils.h"

void DFS(std::vector<std::vector<Node> > &nodes, const Point& in, const Point& out);
void BFS(std::vector<std::vector<Node> > &nodes, const Point& in, const Point& out);
void findConnexe(std::vector<std::vector<Node> > &nodes, const Point& start, const char& c);
void findConnexe(std::vector<std::vector<Node> > &nodes);
bool findPath(std::vector<std::vector<Node> > &nodes, std::vector<std::vector<Node> > &path, const Point& in, const Point& out);
bool findIO(const std::vector<std::vector<Node> > &nodes, Point& in, Point& out);

#endif
