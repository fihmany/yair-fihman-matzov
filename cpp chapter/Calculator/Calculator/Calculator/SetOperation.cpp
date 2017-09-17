#include "SetOperation.h"


bool SetOperation::supportsOperation(std::string &op_string)
{
	if (op_string.compare("set") == 0 || op_string.compare("=") == 0)
	{
		return true;
	}
	return false;
}

int SetOperation::requiredParameterd()
{
	return 1;
}

double SetOperation::calcResult(double currVal, std::vector<std::string>& parameters)
{
	double addParm = 0;
	try
	{
		addParm = std::stod(parameters[0]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (currVal);
	}
	return (addParm);
}
