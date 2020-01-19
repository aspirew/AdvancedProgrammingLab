#pragma once
#include "CONST_H.h"
#include <chrono>

class Timer {

public:

	Timer() {
		setTime(DEFAULT_TIME);
	}

	Timer(int stopMethodTime) {
		setTime(stopMethodTime);
	}

	void setTime(int time) { this->stopMethodTime = time; }

	void startTimer() { this->time = std::chrono::high_resolution_clock::now(); }

	bool hasTimePassed() { 
		auto t2 = std::chrono::high_resolution_clock::now();
		int timePassed = std::chrono::duration_cast<std::chrono::seconds>(t2 - time).count();
		return timePassed >= stopMethodTime;
	}

//private:

	std::chrono::steady_clock::time_point time = std::chrono::high_resolution_clock::now();
	int stopMethodTime;

};