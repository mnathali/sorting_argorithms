#include <iostream>

template <class Type>
void merge(Type *A, std::size_t p, std::size_t q, std::size_t r)
{
	std::size_t n_1 = q - p + 1, n_2 = r - q;
	Type *L = new Type[n_1], *R = new Type[n_2];

	for (std::size_t i = 0; i < n_1; ++i)
		L[i] = A[p + i];
	for (std::size_t i = 0; i < n_2; ++i)
		R[i] = A[q + i + 1];
	for (std::size_t k = p, i = 0, j = 0; k <= r; ++k)
	{
		if ((i < n_1 && L[i] <= R[j]) || !(j < n_2))
		{
			A[k] = L[i];
			i += 1;
		}
		else
		{
			A[k] = R[j];
			j += 1;
		}
	}
	delete [] L;delete [] R;
}


template <class Type>
void merge_sort(Type *A, std::size_t p, std::size_t r)
{
	if (p < r)
	{
		std::size_t q = (p+r)/2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A,p,q,r);
	}
}
