#include <iostream>

template <class Type>
std::size_t partition(Type *A, std::size_t p, std::size_t r)
{
	Type x = A[r];
	std::size_t i = p;

	for (std::size_t j = p; j < r; ++j)
	{
		if (A[j] <= x)
		{
			std::swap(A[i], A[j]);
			i += 1;
		}
	}
	std::swap(A[i], A[r]);
	return (i);
}


template <class Type>
void quicksort(Type *A, std::size_t p, std::size_t r)
{
	if (p < r)
	{
		std::size_t q = partition(A, p, r);
		if (p != q)
			quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}