#pragma once
#include "CalculatorOperation.h"
#include <iostream>
#include <locale>
#include <exception>
class DivOperation : public CalculatorOperation
{
public:
	virtual bool supportsOperation(std::string &op_string);
	virtual int requiredParameterd();
	virtual double calcResult(double currVal, std::vector<std::string> &parameters);
};

