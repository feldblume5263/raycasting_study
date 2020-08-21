#include <stdio.h>
#include <stdlib.h>

#include "./mlx/mlx.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17

// key num은 지정되어 있는 듯.
#define KEY_W	13
#define KEY_S	1
#define KEY_ESC	53

typedef struct	s_param
{
	int			x;
}				t_param;

void			param_init(t_param *param)
{
	param->x = 3;
}

int				key_press(int keycode, t_param *param)
{
	static int	a = 0;

	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

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
	printf("'S key': Subtract 1 from x\n");
	printf("'ESC key': Exit this program\n");
	printf("'Other keys': print current x \n");
	printf("-------------------------------\n");
	printf("Current x = 3\n");

	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx);
}
