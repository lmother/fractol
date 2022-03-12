#include "./includes/fractol.h"

void	ft_mandelbrot(t_cplain *p)
{
	p->c.re = p->min.re + p->x * p->factor.re;
	p->z = ft_init_compl(p->c.re, p->c.im);
	p->i = 0;
	while (pow(p->z.re, 2.0) + pow(p->z.im, 2.0) <= 4 && p->i < p->max_i)
	{
		p->z = ft_init_compl(pow(p->z.re, 2.0) - pow(p->z.im, 2.0)
				+ p->c.re, 2.0 * p->z.re * p->z.im + p->c.im);
		p->i++;
	}
}

void	ft_julia(t_cplain *p)
{
	p->c.re = p->min.re + p->x * p->factor.re;
	p->z = ft_init_compl(p->c.re, p->c.im);
	p->i = 0;
	while (pow(p->z.re, 2.0) + pow(p->z.im, 2.0) <= 4 && p->i < p->max_i)
	{
		p->z = ft_init_compl(pow(p->z.re, 2.0) - pow(p->z.im, 2.0)
				+ p->k.re, 2.0 * p->z.re * p->z.im + p->k.im);
		p->i++;
	}
}

void	ft_burning_ship(t_cplain *p)
{
	p->c.re = p->min.re + p->x * p->factor.re;
	p->z = ft_init_compl(p->c.re, p->c.im);
	p->i = 0;
	while (pow(p->z.re, 2.0) + pow(p->z.im, 2.0) <= 4 && p->i < p->max_i)
	{
		p->z = ft_init_compl(pow(p->z.re, 2.0) - pow(p->z.im, 2.0)
				+ p->c.re, -2.0 * p->z.re * fabs(p->z.im) + p->c.im);
		p->i++;
	}
}

int	main(int agrv, char **agrc)
{
	t_cplain	p;

	if ((agrv == 2 && ft_fractal_is(agrc[1]))
		|| (agrv == 3 && ft_fractal_is(agrc[1])))
	{
		p = ft_init_default();
		if (ft_fractal_is(agrc[1]) == 1)
			p.number_fractol = 1;
		else if (ft_fractal_is(agrc[1]) == 2
			&& agrv == 3 && agrc[2][0] > '0' && agrc[2][0] < '9')
		{
			p.number_fractol = 2;
			ft_julia_set(agrc[2][0], &p);
		}
		else if (ft_fractal_is(agrc[1]) == 2)
		{
			p.number_fractol = 2;
			ft_julia_set('0', &p);
		}
		else if (ft_fractal_is(agrc[1]) == 3)
			p.number_fractol = 3;
		ft_draw_fol(p);
	}
	ft_print_info();
	return (0);
}
