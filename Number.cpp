#include "Number.h"
#include <cmath>
#include <iostream>


Number::Number() : first(0), second(0) {}
Number::Number(int f, int s) : first(f), second(s) {}
Number::Number(const Number& other) : first(other.first), second(other.second) {}
Number::~Number() {}

double Number::Connection(int first_part, int second_part) {
	int k = 1;
	if (second_part > 0) {
		k = static_cast<int>(log10(second_part)) + 1;
	}

	double value = first_part + (second_part / pow(10, k));

	return value;
}

double Number::multiply(int number) {
	double value = Connection(first, second);

	value *= number;

	first = static_cast<int>(value);

	double fractional = value - first;

	int new_second = static_cast<int>(round(fractional * 100));

	second = new_second;

	return Connection(first, second);
}

Number& Number::operator=(const Number& other) {
	first = other.first;
	second = other.second;

	return *this;
}

Number::operator string() const {
	stringstream ss;

	ss << "First: " << first << endl;
	ss << "Second: " << second << endl;

	return ss.str();
}

ostream& operator << (ostream& out, const Number& other) {
	out << string(other);
	return out;
}

istream& operator >>(istream& in, Number& other) {
	cout << "First: "; in >> other.first;
	cout << "Second: "; in >> other.second;

	cout << endl;
	return in;
}

Number& Number::operator ++() {
	first++;
	return *this;
}

Number& Number::operator --() {
	first--;
	return *this;
}

Number Number::operator ++(int) {
	Number t(*this);
	first++;
	return t;
}

Number Number::operator --(int) {
	Number t(*this);
	first--;
	return t;
}

