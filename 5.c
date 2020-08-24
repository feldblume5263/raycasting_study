#include <stdio.h>
#include "./mlx/mlx.h"

typedef struct	s_img {
	void	*img_ptr;
	int		*data;

	int		height;
	int		width;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx {
	void	*mlx_ptr;
	void	*win;
}				t_mlx;

int				main(void)
{
	t_mlx		*mlx;
	int			count_w;
	int			count_h;
	t_img		img;

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, 500, 500, "modify_IMG");

	img.img_ptr = mlx_xpm_file_to_image(mlx, "./textures/wall_s.xpm",  &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	count_h = 0;
	while (count_h < img.height)
	{
		count_w = 0;
		while (count_w < img.width / 2)
		{
			if (count_w % 2 && count_h % 2)
				img.data[count_h * img.width + count_w] = 0xFFFFFF;
			else if (!(count_w % 2) && count_h % 2)
				img.data[count_h * img.width + count_w] = 0xFF0000;
			else if (count_w % 2 && !(count_h % 2))
				img.data[count_h * img.width + count_w] = 0xFF0000;
			else if (!(count_w % 2) && !(count_h % 2))
				img.data[count_h * img.width + count_w] = 0xFFFFFF;
			count_w++;
		}
		count_h++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
