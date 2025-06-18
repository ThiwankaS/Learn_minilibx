#ifndef MY_DRAWING_H
# define MY_DRAWING_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../ft_libft/libft.h"
# include "../ft_libft/ft_printf.h"
# include "../ft_libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1000
# define HEIGHT 800
# define EVENT_CLOSE 17
# define MASK_NO_EVENT 0L

#define WHITE      0xFFFFFF
#define BLACK      0x000000
#define RED        0xFF0000
#define GREEN      0x00FF00
#define BLUE       0x0000FF
#define YELLOW     0xFFFF00
#define CYAN       0x00FFFF
#define MAGENTA    0xFF00FF
#define GRAY       0x808080
#define LIGHT_GRAY 0xD3D3D3
#define DARK_GRAY  0xA9A9A9
#define ORANGE     0xFFA500
#define BROWN      0xA52A2A
#define PURPLE     0x800080
#define PINK       0xFFC0CB
#define LIME       0xBFFF00
#define NAVY       0x000080
#define OLIVE      0x808000
#define TEAL       0x008080
#define MAROON     0x800000

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int line_size;
	int bpp;
	int endian;
} t_mlx;

int close_window(t_mlx *mlx);
void put_pixel(t_mlx *mlx, int x, int y, int color);

void draw_sphere(t_mlx *mlx);
#endif
