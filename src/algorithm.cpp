#include "../include/algorithm.h"

void DFS(std::vector<std::vector<Node> > &nodes, const Point& in, const Point& out){
    apply(nodes, unprocess);
    apply(nodes, unmark);

    std::stack<Node*> s;
    s.push(&nodes[in.y][in.x]);

    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        if(!node->processed){
            node->processed = true;
            node->text = (node->text==UNMARKED?MARKED:node->text);

            Neighbor* nb = node->first;
            while(nb){
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
    apply(nodes, unprocess);
    apply(nodes, unmark);

    std::queue<Node*> q;
    q.push(&nodes[in.y][in.x]);
    nodes[in.y][in.x].processed = true;
    nodes[in.y][in.x].text = (nodes[in.y][in.x].text==UNMARKED?MARKED:nodes[in.y][in.x].text);

    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        Neighbor* nb = n->first;
        while(nb){
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

void findConnexe(std::vector<std::vector<Node> > &nodes, const Point& start, const char& c){
    nodes[start.y][start.x].text = c;
    nodes[start.y][start.x].processed = true;
    Neighbor* nb = nodes[start.y][start.x].first;
    while(nb){
        if(!nodes[nb->pos.y][nb->pos.x].processed){
            findConnexe(nodes, Point(nb->pos.x, nb->pos.y), c);
        }
        nb = nb->next;
    }
}

void findConnexe(std::vector<std::vector<Node> > &nodes){
    apply(nodes, unprocess);
    char c = 'A';
    for(int h=0 ; h<nodes.size() ; h++){
        for(int w=0 ; w<nodes[h].size() ; w++){
            if(!nodes[h][w].processed){
                findConnexe(nodes, Point(w,h), c++);
            }
        }
    }
}

bool findPath(std::vector<std::vector<Node> > &nodes, std::vector<std::vector<Node> > &path, const Point& in, const Point& out){
    if(path.size()==0){
        path.resize(nodes.size(), std::vector<Node> (nodes[0].size(), Node()));
    }

    nodes[in.y][in.x].processed = true;
    path[in.y][in.x] = nodes[in.y][in.x];
    Neighbor* nb = nodes[in.y][in.x].first;

    while(nb){
        Node* node = &nodes[nb->pos.y][nb->pos.x];
        if(nb->pos==out){
            path[nb->pos.y][nb->pos.x] = *node;
            return true;
        }
        else if(node->text==MARKED && !node->processed){
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
        nb = nb->next;
    }

    return false;
}

bool findIO(const std::vector<std::vector<Node> > &nodes, Point& in, Point& out){
    int found = 0;

    for(int h=0 ; h<nodes.size() ; h++){
        for(int w=0 ; w<nodes[h].size() ; w++){
            if(nodes[h][w].text==IN){
                in = Point(w,h);
                found++;
            }
            else if(nodes[h][w].text==OUT){
                out = Point(w,h);
                found++;
            }
        }
    }

    return (found==2);
}