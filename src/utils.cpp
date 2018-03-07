#include "../include/utils.h"

bool read_file(const char* filename, std::vector<std::string> &lines){
    std::ifstream file(filename);
    if(file){
        std::string line;
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

bool read_labyrinth(const char* filename, std::vector<std::vector<Node> > &nodes){
    std::vector<std::string> lines;
    if(read_file(filename, lines)){
        int width = (lines[0].size()-1)/2;
        int height = (lines.size()-1)/2;
        nodes.resize(height, std::vector<Node>(width, Node()));

        int x=0, y=0;

        for(int i=1 ; i<lines.size() ; i+=2){
            for(int j=1 ; j<lines[i].size() ; j+=2){
                std::vector<Neighbor*> nbs;

                if(lines[i-1][j]==' '){
                    nbs.push_back(new Neighbor(y-1, x, NULL));
                }
                if(lines[i+1][j]==' '){
                    nbs.push_back(new Neighbor(y+1, x, NULL));
                }
                if(lines[i][j-1]==' '){
                    nbs.push_back(new Neighbor(y, x-1, NULL));
                }
                if(lines[i][j+1]==' '){
                    nbs.push_back(new Neighbor(y, x+1, NULL));
                }

                nodes[y][x].neighbors = nbs.size();

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

void print(const std::vector<std::vector<Node> > &nodes, std::ostream &os){
    for(int i=0 ; i<nodes.size() ; i++){
        for(int j=0 ; j<nodes[i].size() ; j++){
            os << (nodes[i][j].flag?" X ":" * ");
        }
        os << std::endl;
    }
}

void free_memory(const std::vector<std::vector<Node> > &nodes){
    for(int i=0 ; i<nodes.size() ; i++){
        for(int j=0 ; j<nodes[i].size() ; j++){
            Neighbor* nb = nodes[i][j].first;
            while(nb!=NULL){
                Neighbor *tmp = nb->next;
                delete nb;
                nb = tmp;
            }
        }
    }
}
