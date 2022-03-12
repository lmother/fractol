#include "./includes/fractol.h"

double	ft_interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int	ft_zoom(int key, int x, int y, t_cplain *p)
{
	t_comp	mouse;
	double	interpolation;
	double	zoom;

	if ((key == 4 || key == 5))
	{
		mouse = ft_init_compl(
				(double)x / (WIDTH / (p->max_re - p->min.re))
				+ p->min.re,
				(double)y / (HEIGHT / (p->max_im - p->min.im))
				* -1 + p->max_im);
		if (key == 4)
			zoom = 0.80;
		else
			zoom = 1.20;
		interpolation = 1.0 / zoom;
		p->min.re = ft_interpolate(mouse.re, p->min.re, interpolation);
		p->min.im = ft_interpolate(mouse.im, p->min.im, interpolation);
		p->max_re = ft_interpolate(mouse.re, p->max_re, interpolation);
		p->max_im = ft_interpolate(mouse.im, p->max_im, interpolation);
		ft_init_im_factor(p);
		ft_draw_fol(*p);
	}
	return (0);
}
