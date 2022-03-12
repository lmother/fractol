#include "./includes/fractol.h"

void	ft_init_im_factor(t_cplain *p)
{
	p->max_im = (p->min.im + (p->max_re - p->min.re) * HEIGHT / WIDTH);
	p->factor = ft_init_compl((p->max_re - p->min.re) / (WIDTH - 1),
			(p->max_im - p->min.im) / (HEIGHT - 1));
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_create_rgb(double i, double max_i, int c_shift)
{
	t_color	c;

	c.t = i / max_i;
	c.r = (int)(9 * (1 - c.t) * pow(c.t, 3) * 255);
	c.g = (int)(15 * pow((1 - c.t), 2) * pow(c.t, 2) * 255);
	c.b = (int)(8.5 * pow((1 - c.t), 3) * c.t * 255);
	return ((int)c.t << 24 | (c.r + (int)(c_shift * 1.5)) << 16 |
			(c.g + (int)(c_shift * 1.2)) << 8 | (c.b + (int)(c_shift * 1.7)));
}

void	ft_draw_fol(t_cplain p)
{
	mlx_hook(p.win, 4, 0L, ft_zoom, &p);
	mlx_hook(p.win, 2, 0L, press_key, &p);
	ft_fol(p);
	mlx_put_image_to_window(p.mlx, p.win, p.img.img, 0, 0);
	mlx_loop(p.mlx);
}

void	ft_fol(t_cplain p)
{
	while (p.y < HEIGHT)
	{
		p.c.im = p.max_im - p.y * p.factor.im;
		p.x = 0;
		while (p.x < WIDTH)
		{
			if (p.number_fractol == 2)
				ft_julia(&p);
			else if (p.number_fractol == 3)
				ft_burning_ship(&p);
			else if (p.number_fractol == 1)
				ft_mandelbrot(&p);
			my_pixel_put(&p.img, p.x, p.y,
				ft_create_rgb(p.i, p.max_i, p.color));
			p.x++;
		}
		p.y++;
	}
}
