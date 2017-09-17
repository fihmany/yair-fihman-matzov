#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include "CalculatorOperation.h"
#include "AddOperation.h"
#include "DivOperation.h"
#include "MulOperation.h"
#include "PowOperation.h"
#include "SetOperation.h"
#include "SqrtOperation.h"
#include "SubOperation.h"

class Calculator
{
public:
	///constract the calc and adds the supported modules 
	Calculator();
	///runs the calc and hendles the io
	void Operate();
	///remove the modules from the memory
	~Calculator();
private:

	std::vector<CalculatorOperation*> m_operations;
	double m_currvalue;
	///finds the right fucntion 
	///if cant find returns (-1)
	///op = the operator 
	int findRightOperation(std::string &op);

};

