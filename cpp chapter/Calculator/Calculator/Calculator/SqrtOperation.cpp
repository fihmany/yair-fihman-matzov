#include "SqrtOperation.h"


bool SqrtOperation::supportsOperation(std::string &op_string)
{
	if (op_string.compare("sqrt") == 0 || op_string.compare("+") == 0)
	{
		return true;
	}
	return false;
}

int SqrtOperation::requiredParameterd()
{
	return 0;
}

double SqrtOperation::calcResult(double currVal, std::vector<std::string>& parameters)
{
	if (currVal >= 0)
	{
		return (std::sqrt(currVal));
	}
	std::cerr << "Cant sqrt numbers bellow zero" << std::endl;
	return currVal;
}
