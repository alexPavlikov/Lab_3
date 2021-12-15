#include "Summator.h"
#include <iostream>
#include <fstream>

using namespace std;

Summator::Summator() : ExpressionEvaluator() { }
Summator::Summator(size_t n) : ExpressionEvaluator(n) { }

double Summator::calculate() const {
	double sum = 0.0;
	for (size_t i = 0; i < N; ++i)
	{
		sum += operands[i];
	}
	return sum;
}

void Summator::logToScreen() const {
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
			if (operands[i] >= 0) {
				cout << operands[i] << " + ";
			}
			else {
				cout << '(' << operands[i] << ')' << " + ";
			}
		}
		else {
			if (operands[i] >= 0) {
				cout << operands[i] << endl;
			}
			else {
				cout << '(' << operands[i] << ')' << endl;
			}
			cout << "-> " << Summator::calculate() << endl;
		}
	}
}

void Summator::logToFile(const string& filename) const {
	ofstream fout(filename+".log", ios_base::app);
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
				if (operands[i] >= 0) {
					fout << operands[i] << " + ";
				}
				else {
					fout << '(' << operands[i] << ')' << " + ";
				}
			}
			else {
				if (operands[i] >= 0) {
					fout << operands[i] << endl;
				}
				else {
					fout << '(' << operands[i] << ')' << endl;
				}
				fout << "-> " << Summator::calculate() << endl;
			}
		}
		fout.close();
	}
}
