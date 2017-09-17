#include "AddOperation.h"

bool AddOperation::supportsOperation(std::string &op_string)
{
	if (op_string.compare("add") == 0 || op_string.compare("+") == 0)
	{
		return true;
	}
	return false;
}

int AddOperation::requiredParameterd()
{
	return 1;
}

double AddOperation::calcResult(double currVal, std::vector<std::string>& parameters)
{
	double addParm = 0;
	try
	{
		addParm = std::stod(parameters[0]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (currVal + addParm);
}
