#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() 
{
	N = 20;
	operands = new double[N];
	for (size_t i = 0; i < N; ++i)
	{
		operands[i] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(size_t n) 
{
	N = n;
	operands = new double[N];
	for (size_t i = 0; i < N; ++i)
	{
		operands[i] = 0;
	}
}

ExpressionEvaluator::~ExpressionEvaluator() 
{
	delete[] operands;
}

void ExpressionEvaluator::setOperand(size_t pos, double value) 
{
	if (pos < N) 
	{
		operands[pos] = value;
	}
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) 
{
	for (size_t i = 0; i < n; ++i)
	{
		operands[i] = ops[i];
	}
}
