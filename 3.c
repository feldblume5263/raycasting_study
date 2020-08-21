#include <stdio.h>
#include "./mlx/mlx.h"

int			main(void)
{
	void	*mlx;
	void	*win;

	void	*img;

	int		imgwidth;
	int		imgheigt;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 720, 540, "junhpark's mlx");
	img = mlx_xpm_file_to_image(mlx, "./textures/wall_n.xpm", &imgwidth, &imgheigt);

	mlx_put_image_to_window(mlx, win, img, 310, 220);
	mlx_loop(mlx);
	return (0);
}
