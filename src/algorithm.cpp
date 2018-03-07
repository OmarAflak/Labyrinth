#include "../include/algorithm.h"

void DFS(std::vector<std::vector<Node> > &nodes, int i, int j){
    nodes[i][j].flag = 1;
    Neighbor* nb = nodes[i][j].first;
    while(nb!=nullptr){
        if(!nodes[nb->i][nb->j].flag){
            DFS(nodes, nb->i, nb->j);
        }
        nb = nb->next;
    }
}
