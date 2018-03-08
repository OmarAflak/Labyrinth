#include "../include/algorithm.h"
#include <iostream>

void DFS(std::vector<std::vector<Node> > &nodes, int i, int j){
    nodes[i][j].processed = true;
    nodes[i][j].text = (nodes[i][j].text==' '?'x':nodes[i][j].text);

    Neighbor* nb = nodes[i][j].first;
    while(nb!=nullptr){
        if(!nodes[nb->i][nb->j].processed){
            DFS(nodes, nb->i, nb->j);
        }
        nb = nb->next;
    }
}
