#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>

using namespace std;

CustomExpressionEvaluator::CustomExpressionEvaluator() : ExpressionEvaluator() { }
CustomExpressionEvaluator::CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) { }

double CustomExpressionEvaluator::calculate()const {
	double result = 0.0;
	// x1 – x2 / 2 + x3 / 3 – x4 / 4 + ...
	for (size_t i = 0; i < N; ++i)
	{
		int x = i + 1;
		if (x % 2 == 1) {
			result += (operands[i] / x); 
		}
		else {
			result -= (operands[i] / x); 
		}
	}
	return result;
}

void CustomExpressionEvaluator::logToScreen()const {
	for (size_t i = 0; i < N; ++i)
	{
		if (i != N - 1) {
			cout << "Op" << i << ", ";
		}
		else {
			cout << "Op" << i << " : ";
		}
	}
	for (size_t i = 0; i < N; ++i)
	{
		if (i != N - 1) {
			int x = i + 1;
			if (operands[i] >= 0) {
				if (x % 2 == 1) {
					cout << operands[i] << " - ";
				}
				else {
					cout << operands[i] << " + ";
				}
			}
			else {
				if (x % 2 == 1) {
					cout << '(' << operands[i] << ')' << " - ";
				}
				else {
					cout << '(' << operands[i] << ')' << " + ";
				}
			}
		}
		else {
			if (operands[i] >= 0) {
				cout << operands[i] << endl;
			}
			else {
				cout << '(' << operands[i] << ')' << endl;
			}
			cout << "-> " << CustomExpressionEvaluator::calculate() << endl;
		}
	}
}

void CustomExpressionEvaluator::logToFile(const string& filename) const {
	ofstream fout(filename + ".log", ios_base::app);

	if (fout.is_open())
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (i != N - 1) {
				fout << "Op" << i << ", ";
			}
			else {
				fout << "Op" << i << " : ";
			}
		}
		for (size_t i = 0; i < N; ++i)
		{
			if (i != N - 1) {
				int x = i + 1;
				if (operands[i] >= 0) {
					if (x % 2 == 1) 
					{
						fout << operands[i] << " - ";
					}
					else 
					{
						fout << operands[i] << " + ";
					}
				}
			else {
					if (x % 2 == 1) 
					{
						fout << '(' << operands[i] << ')' << " - ";
					}
					else {
						fout << '(' << operands[i] << ')' << " + ";
					}
				}
			}
			else {
				if (operands[i] >= 0) 
				{
					fout << operands[i] << endl;
				}
				else 
				{
					fout << '(' << operands[i] << ')' << endl;
				}
				fout << "-> " << CustomExpressionEvaluator::calculate() << endl;
			}
		}
		fout.close();
	}
}

void CustomExpressionEvaluator::shuffle() {
	for (size_t i = 0; i < N; i++) {
		if (operands[i] < 0 || operands[i] < 2) {
			for (size_t j = i + 1; j < N; j++) {
				if (operands[j] < 0 || operands[j] < 2) {
					if (operands[i] < operands[j]) {
						double tmp = operands[i];
						operands[i] = operands[j];
						operands[j] = tmp;
					}
				}
			}
		}
	}
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {
	size_t I;
	size_t J;
	if (i < N && j < N) {
		for (I = i + 1; I < j; ++I)
		{
			double tmp = operands[I];
			J = I - 1;
			while (J >= 0 && operands[J] < tmp)
			{
				operands[J + 1] = operands[J];
				J = J - 1;
			}
			operands[J + 1] = tmp;
		}
	}
}
