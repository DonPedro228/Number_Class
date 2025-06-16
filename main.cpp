#include <iostream>
#include "Number.h"
using namespace std;

int main() {
	Number number;

	cout << "Input number: " << endl;
	cin >> number;
	cout << number << endl;

	cout << ++number << endl;
	cout << number++ << endl;
	cout << number << endl;

	int multiplier;
	cout << "Input multiplier number: "; cin >> multiplier;

	double result = number.multiply(multiplier);

	cout << "Result after multiply of number: " << result;


	return 0;
}