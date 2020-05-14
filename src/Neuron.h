#pragma once
#include <vector>
#include <string>


class Neuron
{
private:
	uint32_t inputs_count, study_exampls_count;
	double p, alpha;
	std::vector<double> weights;
	void read_data(std::string file);
	
	struct studyExample 
	{
		std::vector<double> inputs;
		int out;
	};
	std::vector<studyExample> study_examples;

	void penalty(studyExample example, int out);
	bool check(const std::vector<double>&);
public:
	Neuron(std::string file);

	void learning();
	inline uint32_t getCountInputs() const { return inputs_count; }
	inline const std::vector<double> getWeights() const { return weights; } 
	inline const double getP() const { return p; } 

};

