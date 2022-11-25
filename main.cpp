// =================================================================
//
// File: main.cpp
// Author: José Ricardo Rosales Castañeda - A01709449
// Author: Uri Jared Gopar Morales -A01709413
// Date: 25/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string.h>

#include "ugraph.h"

using namespace std;

int main(int argc, char* argv[]) {
	int size, numQuery, MNP;
	string nodeA, nodeB, query, vertex;
	ifstream input (argv[1], ios::in);
	fstream output (argv[2], ios::out);

	if (argc != 3) {
		output << "Usage: " << " <input file> <output file>" << endl;
		return -1;
	}else if (!input) {
		output << "Error: Could not open input file " << argv[1] << endl;
		return -1;
	}else if (!output) {
		output << "Error: Could not open output file " << argv[2] << endl;
		return -1;
	}

	input >> size;

	UMatrixGraph<string> graph(size);

	for(int i = 0; i < size; i++){
		input >> nodeA;
		input >> nodeB;
		graph.addEdge(nodeA, nodeB);
	}

	input >> numQuery;

	for(int i = 0; i < numQuery; i++){
		input >> vertex;
		input >> MNP;

		output << vertex << " " << MNP << endl;
	}

	return 0;
}
