#include "./mlx/mlx.h"

int			main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 720, 540, "mlx_project");
	mlx_loop(mlx);
}
