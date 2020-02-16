#pragma once
#pragma once
class MyInt {

public:

	MyInt() {
		number = 0;
	}
	MyInt(int num) {
		number = num;
	}
	MyInt(MyInt &other) {
		number = other.number;
	}

	MyInt & operator=(const int num) { 
		number = num; 
		return *this;
	}
	MyInt & operator=(const MyInt & other) { 
		number = other.number; 
		return *this;
	}
	MyInt & operator+(const int num) { 
		number += num; 
		return *this;
	}
	MyInt & operator+(const MyInt & other) { 
		number += other.number; 
		return *this;
	}
	MyInt & operator+=(const int num) { 
		number += num; 
		return *this;
	}
	MyInt & operator+=(const MyInt & other) { 
		number += other.number; 
		return *this;
	}
	void operator++(int) {
		++number;
	}
	void operator + () {
		number++;
	}
	void operator--(int) {
		--number;
	}
	void operator -- () {
		number--;
	}
	MyInt & operator-(const int num) { 
		number -= num; 
		return *this;
	}
	MyInt & operator-(const MyInt & other) { 
		number -= other.number; 
		return *this;
	}
	MyInt & operator-=(const int num) { 
		number -= num; 
		return *this;
	}
	MyInt & operator-=(const MyInt & other) { 
		number -= other.number; 
		return *this;
	}
	MyInt & operator*(const int num) { 
		number *= num; 
		return *this;
	}
	MyInt & operator*(const MyInt & other) { 
		number *= other.number; 
		return *this;
	}
	MyInt & operator*=(const int num) {
		number *= num; 
		return *this;
	}
	MyInt & operator*=(const MyInt & other) { 
		number *= other.number; 
		return *this;
	}
	MyInt & operator/(const int num) { 
		number /= num; 
		return *this;
	}
	MyInt & operator/(const MyInt & other) {
		number /= other.number; 
		return *this;
	}
	MyInt & operator/=(const int num) { 
		number /= num; 
		return *this;
	}
	MyInt & operator/=(const MyInt & other) { 
		number /= other.number; 
		return *this;
	}
	MyInt & operator%(const int num) { 
		number %= num; 
		return *this;
	}
	MyInt & operator%(const MyInt & other) { 
		number %= other.number; 
		return *this;
	}
	MyInt & operator%=(const int num) { 
		number %= num; 
		return *this;
	}
	MyInt & operator%=(const MyInt & other) { 
		number %= other.number; 
		return *this;
	}

	operator int() const {
		return number;
	}

	friend std::ostream& operator<<(std::ostream &os, MyInt &p) {
		os << p.number;
		return os;
	}

private:

	int number;
};