//                     Павликов А.О. ИВТ-4(уск) Вариант 7
//   Вид выражения CustomExpression : result = x1 – x2 / 2 + x3 / 3 – x4 / 4 + ...

//   Порядок создания и инициализации объектов подклассов :
//    Summator: 2 операнда, присвоить поэлементно 39.1, -12.7.
//    Multiplier : 4 операнда, присвоить группой - 4.5, 2, 3, -10.
//    CustomExpressionEvaluator : 6 операндов, присвоить группой 5, 16, -3, 10, 12.

//   Метод shuffle() – отсортировать все отрицательные операнды в порядке убывания.
//   Метод shuffle(size_t i, size_t j) – отсортировать все операнды между i - ым и j - ым.

//   Формат вывода :
//    Op1, Op2, Op3, Op4 : (-4.5) х 2 х 3 х (-10)
//    -> 270

#include <iostream>
#include "ExpressionEvaluator.h"
#include "Summator.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"

using namespace std;

int main() 
{
	ExpressionEvaluator* ex[3];

	ex[0] = new Summator(2);
	ex[0]->setOperand(0, 39.1);
	ex[0]->setOperand(1, -12.7);

	ex[1] = new Multiplier(4);
	double* ops_mult = new double[4]{ -4.5, 2, 3, -10 };
	ex[1]->setOperands(ops_mult, 4);

	ex[2] = new CustomExpressionEvaluator(6);
	double* ops_custom = new double[6]{ 5, 16, -3, 10, 12 };
	ex[2]->setOperands(ops_custom, 6);

	for (int i = 0; i < 3; ++i)
	{
		ex[i]->logToScreen();
		ex[i]->logToFile("Log");
		cout << endl;
	}

	for (int i = 0; i < 3; ++i)
	{
		IShuffle* isShuffle = dynamic_cast<IShuffle*>(ex[i]);
		if (isShuffle)
		{
			isShuffle->shuffle();
			ex[i]->logToScreen();
		}
	}

	for (int i = 0; i < 3; ++i) {
		delete ex[i];
	}
	return 0;
}