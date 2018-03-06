#include <iostream>
#include <fstream>
#include <vector>

struct Neighbor{
	int i;
	int j;
	Neighbor* next;

	Neighbor(){
		this->next = NULL;
	}

	Neighbor(int i, int j, Neighbor* next){
		this->i = i;
		this->j = j;
		this->next = next;
	}
};

struct Node{
	int neighbors;
	Neighbor* first;
	bool processed;

	Node(){
		this->neighbors = 0;
		this->first = NULL;
		this->processed = false;
	}
};

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
		nodes.resize(width, std::vector<Node>(height, Node()));

		int x=0, y=0;

		for(int i=1 ; i<lines.size() ; i+=2){
			for(int j=1 ; j<lines[i].size() ; j+=2){
				std::vector<Neighbor> nbs;
				int neighbors = 0;

				if(lines[i-1][j]==' '){
					nodes[x][y].neighbors++;
					nbs.push_back(Neighbor(x-1, y, NULL));
				}
				if(lines[i+1][j]==' '){
					nodes[x][y].neighbors++;
					nbs.push_back(Neighbor(x+1, y, NULL));
				}
				if(lines[i][j-1]==' '){
					nodes[x][y].neighbors++;
					nbs.push_back(Neighbor(x, y-1, NULL));
				}
				if(lines[i][j+1]==' '){
					nodes[x][y].neighbors++;
					nbs.push_back(Neighbor(x, y+1, NULL));
				}

				if(nodes[x][y].neighbors!=0){
					nodes[x][y].first = new Neighbor(nbs[0].i, nbs[0].j, nbs[0].next);
					Neighbor* last = nodes[x][y].first;
					for(int k=1 ; k<nbs.size() ; k++){
						last->next = new Neighbor(nbs[0].i, nbs[0].j, nbs[0].next);
					}
				}

				y++;
			}
			y=0;
			x++;
		}

		return true;
	}
	return false;
}

int main(){
	std::vector<std::vector<Node> > nodes;
	if(read_labyrinth("laby", nodes)){
		for(int i=0 ; i<nodes.size() ; i++){
			for(int j=0 ; j<nodes[i].size() ; j++){
				std::cout << "[" << i << "][" << j << "] : " << nodes[i][j].neighbors << std::endl;
			}
		}
	}
}
