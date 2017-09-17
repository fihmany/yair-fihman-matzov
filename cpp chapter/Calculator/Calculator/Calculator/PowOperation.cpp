#include "PowOperation.h"


bool PowOperation::supportsOperation(std::string &op_string)
{
	if (op_string.compare("pow") == 0 || op_string.compare("^") == 0)
	{
		return true;
	}
	return false;
}

int PowOperation::requiredParameterd()
{
	return 1;
}

double PowOperation::calcResult(double currVal, std::vector<std::string>& parameters)
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
	return (std::pow(currVal, addParm));
}
