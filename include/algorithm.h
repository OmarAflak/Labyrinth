#ifndef ALGORITHM
#define ALGORITHM

#include <vector>
#include <queue>
#include <stack>

#include "Node.h"

void DFS(std::vector<std::vector<Node> > &nodes, Point in, Point out);
void BFS(std::vector<std::vector<Node> > &nodes, Point in, Point out);
std::vector<Node> findPath(std::vector<std::vector<Node> > &nodes, Point in, Point out);

#endif
