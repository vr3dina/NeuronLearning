#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>

#include "Neuron.h"

using namespace std;


void printResults(const Neuron& neuron) 
{
	auto weight = neuron.getWeights();
	for (size_t i = 0; i < neuron.getCountInputs(); i++) 
		cout << "w" + to_string(i + 1) + " = " << weight[i] << endl;
	
	cout << "p = " << neuron.getP() << endl;
}


int main(int argc, char *argv[])
{
	//string file = "1.txt";
	string file = "2.txt";
	//string file = "gopnik.txt";
	Neuron n("res/" + file);
	n.learning();
	printResults(n);

	//system("pause");

	return 0;
}