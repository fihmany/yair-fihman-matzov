#include "DivOperation.h"

bool DivOperation::supportsOperation(std::string &op_string)
{
	if (op_string.compare("div") == 0 || op_string.compare("/") == 0)
	{
		return true;
	}
	return false;
}

int DivOperation::requiredParameterd()
{
	return 1;
}

double DivOperation::calcResult(double currVal, std::vector<std::string>& parameters)
{
	double addParm = 1;
	try
	{
		addParm = std::stod(parameters[0]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (addParm == 0)
	{
		addParm = 1;
	}
	return (currVal / addParm);
}
