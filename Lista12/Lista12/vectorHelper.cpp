template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		os << v[i] << " ";
	}
	return os;
}

template <typename T>
std::vector<T> deserializeVec(std::istream &is, int size) {
	std::vector<T> v(size);
	for (int i = 0; i < size; i++) {
		T result;
		is >> result;
		v[i] = result;
	}

	return v;
}

std::vector<MinMaxValues<double>> deserializeVec(std::istream &is, int size) {
	std::vector<MinMaxValues<double>> v(size);
	for (int i = 0; i < size; i++) {
		double result1, result2;
		is >> result1;
		is >> result2;
		v[i] = { result1, result2 };
	}

	std::string foo;

	std::getline(is, foo, ' ');
	std::getline(is, foo, ' ');

	return v;
}

