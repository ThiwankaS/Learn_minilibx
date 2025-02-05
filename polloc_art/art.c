#include <stdlib.h>
#include "minilibx/mlx.h"

#define WIDTH 700
#define HEIGHT 500

int main (void)
{
	void *mlx_connection = mlx_init();
	void *mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT,"My first window");
	for(int y = 0.1 * HEIGHT; y < 0.9 * HEIGHT ; y++)
	{
		for(int x = 0.1 * WIDTH; x < 0.9 * WIDTH; x++)
		{
			mlx_pixel_put(mlx_connection, mlx_window,x, y, rand() % 0x100000);
		}
	}
	for(int y = 0.5 * HEIGHT; y < 0.75 * HEIGHT ; y++)
	{
		for(int x = 0.7 * WIDTH; x < 0.75 * WIDTH; x++)
		{
			mlx_pixel_put(mlx_connection, mlx_window,x, y, 0xCC00CC);
		}
	}
	mlx_string_put(mlx_connection, mlx_window, 0.8 * WIDTH , 0.95 * HEIGHT,0x0000FF,"Thiwanka Somachandra");
	mlx_loop(mlx_connection);
	return (0);
}
