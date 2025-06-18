#include "../includes/my_drawing.h"

void draw_sphere(t_mlx *mlx)
{
	float r = 100;
	float theta, phi;

	for(theta = 0; theta <= M_PI; theta += 0.01)
	{
		for(phi = 0; phi <= 2 * M_PI; phi += 0.01)
		{
			float x = r * sinf(theta) * cosf(phi);
			float y = r * sinf(theta) * sinf(phi);
			float r = r * cosf(theta);

			int screen_x = x + WIDTH / 2;
			int screen_y = y + HEIGHT / 2;
			put_pixel(mlx, screen_x, screen_y, MAROON);
		}
	}
}
