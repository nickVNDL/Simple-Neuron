#include "Neuron.h"
#include <iostream>
#include <iomanip>
#include <math.h>

Neuron::Neuron(float value)
{
	this->setValue(value);
}

Neuron::Neuron(float value, Func activation)
{
	this->setValue(value);
	this->type = activation;
}

void Neuron::activate()
{
	if (type == Func::TANH)
		this->activatedValue = tanh(this->value);
	else if (type == Func::RELU)
	{
		this->activatedValue = 0;
		if (this->value > 0)
			this->activatedValue = this->value;
	}
	else if (type == Func::SIGM)
		this->activatedValue = 1 / (1 + exp(-this->value));
}

void Neuron::derive()
{
	if (type == Func::TANH)
		this->derivedValue = 1 - this->activatedValue * this->activatedValue;
	else if (type == Func::RELU)
	{
		this->derivedValue = 0;
		if (this->value > 0)
			this->derivedValue = 1;
	}
	else if (type == Func::SIGM)
		this->derivedValue = this->activatedValue * (1 - this->activatedValue);
}

void Neuron::compute()
{
	this->activate();
	this->derive();
}

void Neuron::output()
{
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "Value: " << this->getValue() << ";\n" << "Activated value: " << this->getActivateValue() << ";\nDerived value: " << this->getDerivedValue() << "." << std::endl;
}