#include "Multiplier.h"
#include <iostream>
#include <fstream>

using namespace std;

Multiplier::Multiplier() : ExpressionEvaluator() { }
Multiplier::Multiplier(size_t n) : ExpressionEvaluator(n) { }

double Multiplier::calculate() const 
{
	double res = 1.0;
	for (size_t i = 0; i < N; ++i)
	{
		res *= operands[i];
	}
	return res;
}

void Multiplier::logToScreen() const {
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
				cout << operands[i] << " x ";
			}
			else {
				cout << '(' << operands[i] << ')' << " x ";
			}
		}
		else {
			if (operands[i] >= 0) {
				cout << operands[i] << endl;
			}
			else {
				cout << '(' << operands[i] << ')' << endl;
			}
			cout << "-> " << Multiplier::calculate() << endl;
		}
	}
}

void Multiplier::logToFile(const string& filename) const {
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
				if (operands[i] >= 0) {
					fout << operands[i] << " x ";
				}
				else {
					fout << '(' << operands[i] << ')' << " x ";
				}
			}
			else {
				if (operands[i] >= 0) {
					fout << operands[i] << endl;
				}
				else {
					fout << '(' << operands[i] << ')' << endl;
				}
				fout << "-> " << Multiplier::calculate() << endl;
			}
		}
		fout.close();
	}
}
