#include <iostream>

template <typename Type>
void	max_heapify(Type *p, std::size_t i, std::size_t size)
{
	std::size_t l = 2 * i + 1;
	std::size_t r = 2 * i + 2;
	std::size_t largest;

	if (l <= size-1 && p[l] > p[i])
		largest = l;
	else
		largest = i;
	if (r <= size-1 && p[r] > p[largest])
		largest = r;
	if (largest != i)
	{
		Type tmp = p[i];
		p[i] = p[largest];
		p[largest] = tmp;
		max_heapify(p, largest, size);
	}
}

template<class Type>
void build_max_heap(Type *p, std::size_t size)
{
	for (std::size_t i = (size-1)/2;;--i)
	{
		max_heapify(p,i,size);
		if (i == 0)
			break;
	}
}

template <typename Type>
void	heap_sort(Type *p, std::size_t n)
{
	Type tmp;

	if (n < 2)
		return ;
	build_max_heap(p,n);
	for (std::size_t i = n-1;;--i)
	{
		tmp = p[i];
		p[i] = p[0];
		p[0] = tmp;
		max_heapify(p,0, i);
		if (i == 1)
			break;
	}
}