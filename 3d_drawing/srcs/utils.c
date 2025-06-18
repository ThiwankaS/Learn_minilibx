#include "../includes/my_drawing.h"

int close_window(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

void put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;

	dst = mlx->addr + ((y * mlx->line_size) + (x * (mlx->bpp / 8)));
	*(unsigned int *)dst = color;
}
