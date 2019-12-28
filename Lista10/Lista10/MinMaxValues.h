#pragma once

struct MinMaxValues {
	double min;
	double max;

	friend std::ostream& operator<<(std::ostream& os, const MinMaxValues& minmax) {
		os << minmax.min << " " << minmax.max;
		return os;
	}
};