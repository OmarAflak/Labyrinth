#include "../include/utils.h"

bool read_file(const char* filename, std::vector<std::string> &lines){
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

bool read_labyrinth(const char* filename, std::vector<std::vector<Node> > &nodes, std::vector<std::string> &labyrinth){
    if(read_file(filename, labyrinth)){
        int width = (labyrinth[0].size()-1)/2;
        int height = (labyrinth.size()-1)/2;
        nodes.resize(height, std::vector<Node>(width, Node()));

        int x=0, y=0;

        for(int i=1 ; i<labyrinth.size() ; i+=2){
            for(int j=1 ; j<labyrinth[i].size() ; j+=2){
                std::vector<Neighbor*> nbs;

                if(labyrinth[i-1][j]==' '){
                    nbs.push_back(new Neighbor(y-1, x, NULL));
                }
                if(labyrinth[i+1][j]==' '){
                    nbs.push_back(new Neighbor(y+1, x, NULL));
                }
                if(labyrinth[i][j-1]==' '){
                    nbs.push_back(new Neighbor(y, x-1, NULL));
                }
                if(labyrinth[i][j+1]==' '){
                    nbs.push_back(new Neighbor(y, x+1, NULL));
                }

                nodes[y][x].neighbors = nbs.size();
                nodes[y][x].text = labyrinth[i][j];

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
    for(int i=0 ; i<labyrinth.size() ; i++){
        for(int j=0 ; j<labyrinth[i].size() ; j++){
            if(i%2!=0 && j%2!=0){
                os << nodes[y][x].text;
                x++;
            }
            else{
                os << labyrinth[i][j];
            }
        }
        os << std::endl;

        if(i%2!=0){
            x=0;
            y++;
        }
    }
}

void reset(std::vector<std::vector<Node> > &nodes){
    for(int i=0 ; i<nodes.size() ; i++){
        for(int j=0 ; j<nodes[i].size() ; j++){
            nodes[i][j].processed = false;
            nodes[i][j].text = ' ';
        }
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
