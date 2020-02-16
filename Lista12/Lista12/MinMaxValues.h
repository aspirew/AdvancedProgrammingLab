#pragma once

template <typename T>
struct MinMaxValues {
	T min;
	T max;

	friend std::ostream& operator<<(std::ostream& os, const MinMaxValues<T>& minmax) {
		os << minmax.min << " " << minmax.max;
		return os;
	}
};