#include "utils.h"

void	print_array(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			printf("%c", arr[i][j++]);
		printf("\n");
		i++;
	}
}