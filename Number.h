#pragma once
#include <string>
#include <sstream>
using namespace std;


class Number {
private:
	int first;
	int second;
public:
	Number();
	Number(int f, int s);
	Number(const Number& other);
	~Number();


	int getFirst() const { return first; }
	int getSecond() const { return second; }

	void setFirst(int value) { first = value; }
	void setSecond(int value) { second = value; }


	double Connection(int first_part, int second_part);
	double multiply(int number);

	Number& operator = (const Number&);
	operator string() const;

	friend ostream& operator << (ostream&, const Number&);
	friend istream& operator >> (istream&, Number&);

	Number& operator++();
	Number& operator--();
	Number operator++(int);
	Number operator--(int);
};