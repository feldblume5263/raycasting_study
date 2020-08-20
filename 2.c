#include <stdio.h>
#include <stdlib.h>

#include "./mlx/mlx.h"

typedef struct	s_param
{
	int			x;
	int			y;
	char 		str[3];
}				t_param;

int				main(void)
{
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 720, 540, "mlx");
	printf("-------------------------------\n");
	printf("'W key': Add 1 to x.\n");
	printf("'A key': Subtract 1 from x\n");
	printf("'ESC key': Exit this program\n");
	printf("'Other keys': print current x \n");
	printf("-------------------------------\n");
	printf("Current x = 3\n");

	mlx_hook()
}
