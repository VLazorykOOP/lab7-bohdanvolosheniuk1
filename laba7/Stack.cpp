#include "Stack.h"
template <typename T>
T& Stack<T>::operator[](int index) {
	if (index >= 0 && index < size)
		return array[index];
	else throw std::exception("out of range");
}
