#include "Calculator.h"


Calculator::Calculator()
{
	m_currvalue = 0;
	m_operations.push_back(new AddOperation());
	m_operations.push_back(new DivOperation());
	m_operations.push_back(new MulOperation());
	m_operations.push_back(new PowOperation());
	m_operations.push_back(new SetOperation());
	m_operations.push_back(new SqrtOperation());
	m_operations.push_back(new SubOperation());
}

void Calculator::Operate()
{
	std::cout << "Welcomd to the modular calculator. "<< std::endl;
	std::string input;
	std::vector<std::string> line;
	bool work = true;
	while (work) {
		int func;
		std::cin >> input;
		if ((func = findRightOperation(input)) != -1)
		{
			std::vector<std::string> parms;
			int numOfArgs = m_operations[func]->requiredParameterd();
			for (size_t i = 0; i < numOfArgs; i++)
			{
				std::cin >> input;
				parms.push_back(input);
			}
			m_currvalue = m_operations[func]->calcResult(m_currvalue, parms);
			std::cout << "Current Value is: " << m_currvalue << std::endl;
		}
		else if(input.compare("exit") == 0)
		{
			work = false;
		}
		else
		{
			std::cout << "Operation is'nt supported!" << std::endl;
		}
	} 
	
}


Calculator::~Calculator()
{
	for (auto &operation : m_operations)
	{
		delete operation;
	}
}

int Calculator::findRightOperation(std::string & op)
{
	int i = 0;
	for (auto &operation : m_operations)
	{
		if (operation->supportsOperation(op))
		{
			return i;
		}
		i++;
	}
	return -1;
}
