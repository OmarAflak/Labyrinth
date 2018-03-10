#include "../include/algorithm.h"

void DFS(std::vector<std::vector<Node> > &nodes, const Point& in, const Point& out){
    std::stack<Node*> s;
    s.push(&nodes[in.y][in.x]);

    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        if(!node->processed){
            node->processed = true;
            node->text = (node->text==UNMARKED?MARKED:node->text);

            Neighbor* nb = node->first;
            while(nb!=nullptr){
                if(nb->pos == out){
                    apply(nodes, unprocess);
                    return;
                }

                s.push(&nodes[nb->pos.y][nb->pos.x]);
                nb = nb->next;
            }
        }
    }

    apply(nodes, unprocess);
}

void BFS(std::vector<std::vector<Node> > &nodes, const Point& in, const Point& out){
    std::queue<Node*> q;
    q.push(&nodes[in.y][in.x]);
    nodes[in.y][in.x].processed = true;
    nodes[in.y][in.x].text = (nodes[in.y][in.x].text==UNMARKED?MARKED:nodes[in.y][in.x].text);

    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        Neighbor* nb = n->first;
        while(nb!=nullptr){
            Node* node = &nodes[nb->pos.y][nb->pos.x];
            if(!node->processed){
                q.push(node);
                node->processed = true;
                node->text = (node->text==UNMARKED?MARKED:node->text);

                if(nb->pos == out){
                    apply(nodes, unprocess);
                    return;
                }
            }
            nb = nb->next;
        }
    }

    apply(nodes, unprocess);
}

bool findPath(std::vector<std::vector<Node> > &nodes, std::vector<std::vector<Node> > &path, const Point& in, const Point& out){
    if(path.size()==0){
        path.resize(nodes.size(), std::vector<Node> (nodes[0].size(), Node()));
    }

    nodes[in.y][in.x].processed = true;
    path[in.y][in.x] = nodes[in.y][in.x];
    Neighbor* nb = nodes[in.y][in.x].first;

    while(nb!=nullptr){
        Node* node = &nodes[nb->pos.y][nb->pos.x];
        if(node->text==MARKED && !node->processed){
            std::vector<std::vector<Node> > subpath;
            bool found = findPath(nodes, subpath, nb->pos, out);
            if(found){
                // if subpath reached the target then fuse both arrays
                for(int h=0 ; h<path.size() ; h++){
                    for(int w=0 ; w<path[h].size() ; w++){
                        if(!path[h][w].processed){
                            path[h][w] = subpath[h][w];
                        }
                    }
                }
                return found;
            }
        }
        else if(nb->pos==out){
            path[nb->pos.y][nb->pos.x] = *node;
            return true;
        }
        nb = nb->next;
    }

    return false;
}
