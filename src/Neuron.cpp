#include "Neuron.h"
#include <fstream>

using namespace std;

Neuron::Neuron(string file)
{
	read_data(file);
}

void Neuron::read_data(string file) {
	ifstream fin(file);
	int16_t tmp2;
	fin >> this->inputs_count;
	weights.resize(inputs_count);
	for (size_t i = 0; i < inputs_count; i++)
	{
		fin >> weights[i];
	}
	fin >> p >> alpha;
	fin >> study_exampls_count;
	study_examples.resize(study_exampls_count);
	for (size_t i = 0; i < study_exampls_count; i++)
	{
		for (size_t j = 0; j < inputs_count; j++)
		{
			double tmp;
			fin >> tmp;
			study_examples[i].inputs.push_back(tmp);
		}
		fin >> study_examples[i].out;
	}
}

bool Neuron::check(const vector<double>& exaple_inputs)
{
	double sum = 0;
	for (size_t i = 0; i < inputs_count; i++)
		sum += weights[i] * exaple_inputs[i];
	return sum >= p;
}

void Neuron::penalty(studyExample example, int out)
{
	for (size_t i = 0; i < inputs_count; i++)
		weights[i] += alpha * example.inputs[i] * (double(example.out) - double(out));

	p -= alpha * (double(example.out) - double(out));
}

void Neuron::learning()
{
	uint32_t success_count = 0;

	while (success_count != study_exampls_count)
	{
		success_count = 0;
		for (auto example : study_examples)
		{
			int outSignal = check(example.inputs);
			if (outSignal == example.out)
				success_count++;
			else
				penalty(example, outSignal);
		}
	}
}

