#include "Neuron.h"
#include <iostream>
#include <iomanip>

int main()
{
	Neuron firstNeuron = Neuron(0.0);
	firstNeuron.compute();
	firstNeuron.output();
}