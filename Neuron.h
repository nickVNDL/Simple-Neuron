#pragma once

// Перечисления функций активации
enum Func
{
	TANH = 1, // Гиперболический тангенс
	RELU = 2, // RELU
	SIGM = 3  // Сигмоида
};

class Neuron
{
public:
	// Конструкторы
	Neuron(float value); 
	Neuron(float value, Func activation);

	void setValue(float value) { this->value = value; }; // Сеттер входного значения
	void activate(); // Активатор
	void derive(); // Выходное значение
	void output(); // Вывод значений в консоль
	void compute(); // Выисление значений

	// Геттеры
	float getValue() { return this->value; }
	float getActivateValue() { return this->activatedValue; }
	float getDerivedValue() { return this->derivedValue; }

private:
	float value;
	float activatedValue;
	float derivedValue;
	Func type = Func::SIGM;
};