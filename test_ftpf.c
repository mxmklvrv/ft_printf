#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int own;
	int build_in;

	printf("----------just text----------\n");
	own = ft_printf("shla sasha po shosse i sosala sushku\n");
	build_in = printf("shla sasha po shosse i sosala sushku\n");

	printf("----------  chars  ----------\n");
	own = ft_printf("shla sasha po shosse i sosala %c sushku\n", 'y');
	build_in = printf("shla sasha po shosse i sosala %c sushku\n", 'y');
	printf("own: %d vs build_in: %d\n", own, build_in);
}