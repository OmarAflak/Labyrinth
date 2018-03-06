#include <iostream>
#include <fstream>
#include <vector>

#include "../include/utils.h"

int main(){
	std::vector<std::vector<Node> > nodes;
	if(read_labyrinth("data/labyrinth", nodes)){
		for(int i=0 ; i<nodes.size() ; i++){
			for(int j=0 ; j<nodes[i].size() ; j++){
				std::cout << "[" << i << "][" << j << "] : " << nodes[i][j].neighbors << std::endl;
				Neighbor* nb = nodes[i][j].first;
				while(nb!=NULL){
					std::cout << "\t[" << nb->i << "][" << nb->j << "]" << std::endl;
					nb = nb->next;
				}
			}
		}
	}
}
