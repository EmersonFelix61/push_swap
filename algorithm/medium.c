#include "../includes/push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	if (size > 100)
		chunk *= 2;
	return (chunk);
}
