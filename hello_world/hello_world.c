#include "mlx_linux/mlx.h"
#include <stdlib.h>

#define WIDTH 1920
#define HEIGHT 1080
typedef struct s_data
{
	void *img;
	char *addr;
	int bites_per_pixel;
	int line_length;
	int endian;
} t_data;


void my_mlx_pixel_put(t_data *data, int x ,int y, int color)
{
	char *dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
			return;

	dst = data->addr + (y * data->line_length + x * (data->bites_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_circle_line(t_data *data, int xc, int yc, int r, int color)
{
	int x = r, y = 0;
	int p = 1 - r;  // Midpoint algorithm decision variable

	while (x >= y)
	{
		my_mlx_pixel_put(data, xc + x, yc + y, color);
		my_mlx_pixel_put(data, xc - x, yc + y, color);
		my_mlx_pixel_put(data, xc + x, yc - y, color);
		my_mlx_pixel_put(data, xc - x, yc - y, color);
		my_mlx_pixel_put(data, xc + y, yc + x, color);
		my_mlx_pixel_put(data, xc - y, yc + x, color);
		my_mlx_pixel_put(data, xc + y, yc - x, color);
		my_mlx_pixel_put(data, xc - y, yc - x, color);

		y++;

		if (p <= 0)
			p = p + 2*y + 1;
		else
		{
			x--;
			p = p + 2*y - 2*x + 1;
		}
	}
}

void draw_circle_filled(t_data *data, int xc, int yc, int r, int color)
{
	int x = r, y = 0;
	int p = 1 - r;  // Midpoint algorithm decision variable

	while (x >= y)
	{
		for (int i = xc - x; i <= xc + x; i++) {
			my_mlx_pixel_put(data, i, yc + y, color);
			my_mlx_pixel_put(data, i, yc - y, color);
		}
		for (int i = xc - y; i <= xc + y; i++) {
			my_mlx_pixel_put(data, i, yc + x, color);
			my_mlx_pixel_put(data, i, yc - x, color);
		}

		y++;

		if (p <= 0)
			p = p + 2*y + 1;
		else
		{
			x--;
			p = p + 2*y - 2*x + 1;
		}
	}
}

int main (void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello World");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img,&img.bites_per_pixel,&img.line_length,&img.endian);

	//drawing a red dot on my window (5,5)
	my_mlx_pixel_put(&img,25,25,0x00FF0000);

	//drawing a blue color line
	for(int i = 25; i <= 200;i++)
		my_mlx_pixel_put(&img,i,100,0x000000FF);

	//drawing a rectangle
	for(int j = 150; j <= 250; j++)
		for(int i = 25; i <= 500; i++)
			my_mlx_pixel_put(&img,i,j,0x00FF0000);

	//drawing a circle only line
	draw_circle_line(&img, 150, 400, 100, 0x0000FF00);

	//drawing a circle filled withe color
	draw_circle_filled(&img, 150, 650, 100, 0x0000FF00);

	mlx_put_image_to_window(mlx,mlx_win,img.img,0,0);

	mlx_string_put(mlx,mlx_win,25,  40, 0x00FFFFFF,"Dot");
	mlx_string_put(mlx,mlx_win,25, 130, 0x00FFFFFF,"Line");
	mlx_string_put(mlx,mlx_win,25, 280, 0x00FFFFFF,"Ractangle");
	mlx_string_put(mlx,mlx_win,25, 520, 0x00FFFFFF,"Circle (line)");
	mlx_string_put(mlx,mlx_win,25, 770, 0x00FFFFFF,"Circle (filled)");

	mlx_loop(mlx);

	return (0);
}
