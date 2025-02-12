#ifndef FT_GRAPHICS_H
#define FT_GRAPHICS_H

#include <stdlib.h>
#include <math.h>
#include "mlx_linux/mlx.h"

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

typedef struct s_points
{
	int x;
	int y;
} t_point;


//Implemention on the circle.c file
void draw_circle_line(t_data *data, int xc, int yc, int r, int color);
void draw_circle_filled(t_data *data, int xc, int yc, int r, int color);

//Helper fucntions, implementation on the utilities.c file
void my_mlx_pixel_put(t_data *data, int x ,int y, int color);

//Darw line implementaion on line.c file
void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color);

//Implementaion on the triangle.c file
void draw_triangle_line(t_data *data, int x1, int y1 , int x2, int y2, int x3, int y3, int color);
void draw_triangle_filled(t_data *data, int x1, int y1, int x2, int y2, int x3, int y3, int color);

//Implementaion on the hexagon.c file
void draw_hexagon_line(t_data *data,t_point *p1, t_point *p2, t_point *p3, t_point *p4, t_point *p5, t_point *p6, int color);

#endif
