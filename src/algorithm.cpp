#include "../include/algorithm.h"

void DFS(std::vector<std::vector<Node> > &nodes, int i, int j){
    std::stack<Node*> s;
    s.push(&nodes[i][j]);

    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        if(!node->processed){
            node->processed = true;
            node->text = (node->text==' '?'x':node->text);

            if(node->text=='O'){
                return;
            }

            Neighbor* nb = node->first;
            while(nb!=nullptr){
                s.push(&nodes[nb->i][nb->j]);
                nb = nb->next;
            }
        }
    }
}

void BFS(std::vector<std::vector<Node> > &nodes, int i, int j){
    std::queue<Node*> q;
    q.push(&nodes[i][j]);
    nodes[i][j].processed = true;
    nodes[i][j].text = (nodes[i][j].text==' '?'x':nodes[i][j].text);

    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        Neighbor* nb = n->first;
        while(nb!=nullptr){
            if(nodes[nb->i][nb->j].text=='O'){
                return;
            }

            if(!nodes[nb->i][nb->j].processed){
                q.push(&nodes[nb->i][nb->j]);
                nodes[nb->i][nb->j].processed = true;
                nodes[nb->i][nb->j].text = (nodes[nb->i][nb->j].text==' '?'x':nodes[nb->i][nb->j].text);
            }
            nb = nb->next;
        }
    }
}
