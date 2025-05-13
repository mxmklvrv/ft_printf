#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int own;
	int build_in;

	printf("----------just text----------\n");
	own = ft_printf("shla sasha po shosse i sosala sushku\n");
	build_in = printf("shla sasha po shosse i sosala sushku\n");
	printf("own: %d vs build_in: %d\n", own, build_in);

	printf("----------  chars  ----------\n");
	own = ft_printf("shla sasha po shosse i sosala %c sushku\n", 'W');
	build_in = printf("shla sasha po shosse i sosala %c sushku\n", 'W');
	printf("own: %d vs build_in: %d\n", own, build_in);

	printf("----------  string  ----------\n");
	own = ft_printf("shla sasha po shosse i sosala %s sushku\n", "no ne");
	build_in = printf("shla sasha po shosse i sosala %s sushku\n", "no ne");
	printf("own: %d vs build_in: %d\n", own, build_in);

	printf("----------  nothing after percent ----------\n");
	own = ft_printf("shla sasha po shosse i sosala sushku %");
	printf("\n");
	build_in = printf("shla sasha po shosse i sosala sushku %");
	printf("\n");
	printf("own: %d vs build_in: %d\n", own, build_in);

	printf("----------  string, but NULL  ----------\n");
	own = ft_printf("shla sasha po shosse i sosala %s sushku\n", NULL);
	build_in = printf("shla sasha po shosse i sosala %s sushku\n", NULL);
	printf("own: %d vs build_in: %d\n", own, build_in);

	printf("----------  percent after percent ----------\n");
	own = ft_printf("o: %%%%");
	printf("\n");
	build_in = printf("b: %%%%");
	printf("\n");
	printf("own: %d vs build_in: %d\n", own, build_in);

	printf("----------  numd ----------\n");
	own = ft_printf("o: %d", -2147);
	printf("\n");
	build_in = printf("b: %d", -2147);
	printf("\n");
	printf("own: %d vs build_in: %d\n", own, build_in);

	printf("----------  numi ----------\n");
	own = ft_printf("o: %i %d", 12, 34);
	printf("\n");
	build_in = printf("b: %i %d", 12, 34);
	printf("\n");
	printf("own: %i vs build_in: %i\n", own, build_in);
}