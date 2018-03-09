#ifndef ALGORITHM
#define ALGORITHM

#include <vector>
#include <queue>
#include <stack>

#include "Node.h"

void DFS(std::vector<std::vector<Node> > &nodes, const Point& in, const Point& out);
void BFS(std::vector<std::vector<Node> > &nodes, const Point& in, const Point& out);
bool findPath(std::vector<std::vector<Node> > &nodes, std::vector<Node> &path, const Point& in, const Point& out);

#endif
