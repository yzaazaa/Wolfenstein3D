#include "utils.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytes;
	size_t			i;

	bytes = (unsigned char *)b;
	i = 0;
	while (i < len)
		bytes[i++] = (unsigned char)c;
	return (b);
}