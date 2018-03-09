#include "../include/algorithm.h"

void DFS(std::vector<std::vector<Node> > &nodes, Point in, Point out){
    std::stack<Node*> s;
    s.push(&nodes[in.y][in.x]);

    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        if(!node->processed){
            node->processed = true;
            node->text = (node->text==' '?'x':node->text);

            Neighbor* nb = node->first;
            while(nb!=nullptr){
                if(nb->pos == out){
                    return;
                }

                s.push(&nodes[nb->pos.y][nb->pos.x]);
                nb = nb->next;
            }
        }
    }
}

void BFS(std::vector<std::vector<Node> > &nodes, Point in, Point out){
    std::queue<Node*> q;
    q.push(&nodes[in.y][in.x]);
    nodes[in.y][in.x].processed = true;
    nodes[in.y][in.x].text = (nodes[in.y][in.x].text==' '?'x':nodes[in.y][in.x].text);

    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        Neighbor* nb = n->first;
        while(nb!=nullptr){
            Node* node = &nodes[nb->pos.y][nb->pos.x];
            if(!node->processed){
                q.push(node);
                node->processed = true;
                node->text = (node->text==' '?'x':node->text);

                if(nb->pos == out){
                    return;
                }
            }
            nb = nb->next;
        }
    }
}
