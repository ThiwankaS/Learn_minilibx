#include "graphics.h"

void draw_hexagon_line(t_data *data,t_point *p1, t_point *p2, t_point *p3, t_point *p4, t_point *p5, t_point *p6, int color)
{
	draw_line(data,p1->x,p1->y,p2->x,p2->y,color);
	draw_line(data,p2->x,p2->y,p3->x,p3->y,color);
	draw_line(data,p3->x,p3->y,p4->x,p4->y,color);
	draw_line(data,p4->x,p4->y,p5->x,p5->y,color);
	draw_line(data,p5->x,p5->y,p6->x,p6->y,color);
	draw_line(data,p6->x,p6->y,p1->x,p1->y,color);
}
