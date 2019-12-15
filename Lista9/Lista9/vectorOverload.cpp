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

	std::string foo;

	std::getline(is, foo, ' ');
	std::getline(is, foo, ' ');

	return v;
}

