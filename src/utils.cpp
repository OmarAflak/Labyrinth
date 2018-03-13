#include "../include/utils.h"

bool readFile(const char* filename, std::vector<std::string> &lines){
    std::ifstream file(filename);
    if(file){
        std::string line;
        lines.resize(0);
        while(!file.eof()){
            getline(file, line);
            if(line!=""){
                lines.push_back(line);
            }
        }
        file.close();
        return true;
    }
    return false;
}

bool readLabyrinth(const char* filename, std::vector<std::vector<Node> > &nodes, std::vector<std::string> &labyrinth){
    if(readFile(filename, labyrinth)){
        int width = (labyrinth[0].size()-1)/2;
        int height = (labyrinth.size()-1)/2;
        nodes.resize(height, std::vector<Node>(width, Node()));

        int x=0, y=0;

        for(int h=1 ; h<labyrinth.size() ; h+=2){
            for(int w=1 ; w<labyrinth[h].size() ; w+=2){
                std::vector<Neighbor*> nbs;

                if(labyrinth[h-1][w]==' '){
                    nbs.push_back(new Neighbor(Point(x, y-1), NULL));
                }
                if(labyrinth[h+1][w]==' '){
                    nbs.push_back(new Neighbor(Point(x, y+1), NULL));
                }
                if(labyrinth[h][w-1]==' '){
                    nbs.push_back(new Neighbor(Point(x-1, y), NULL));
                }
                if(labyrinth[h][w+1]==' '){
                    nbs.push_back(new Neighbor(Point(x+1, y), NULL));
                }

                nodes[y][x].neighbors = nbs.size();
                nodes[y][x].text = labyrinth[h][w];

                if(nodes[y][x].neighbors>0){
                    Neighbor* last = nbs[0];
                    nodes[y][x].first = last;
                    for(int k=1 ; k<nbs.size() ; k++){
                        last->next = nbs[k];
                        last = last->next;
                    }
                }

                x++;
            }
            x=0;
            y++;
        }

        return true;
    }
    return false;
}

void print(const std::vector<std::vector<Node> > &nodes, const std::vector<std::string> &labyrinth, std::ostream &os){
    int x=0, y=0;
    for(int h=0 ; h<labyrinth.size() ; h++){
        for(int w=0 ; w<labyrinth[h].size() ; w++){
            if(h%2!=0 && w%2!=0){
                os << nodes[y][x].text;
                x++;
            }
            else{
                os << labyrinth[h][w];
            }
        }
        os << std::endl;

        if(h%2!=0){
            x=0;
            y++;
        }
    }
}

void apply(std::vector<std::vector<Node> > &nodes, void (*change)(Node& node)){
    for(int h=0 ; h<nodes.size() ; h++){
        for(int w=0 ; w<nodes[h].size() ; w++){
            change(nodes[h][w]);
        }
    }
}

void unprocess(Node& node){
	node.processed = false;
}

void unmark(Node& node){
    if(node.text==MARKED){
        node.text = UNMARKED;
    }
}

void freeMemory(const std::vector<std::vector<Node> > &nodes){
    for(int h=0 ; h<nodes.size() ; h++){
        for(int w=0 ; w<nodes[h].size() ; w++){
            Neighbor* nb = nodes[h][w].first;
            while(nb){
                Neighbor *tmp = nb->next;
                delete nb;
                nb = tmp;
            }
        }
    }
}
