#include "./includes/fractol.h"

int	press_key(int key, t_cplain *p)
{
	if (key == p->key.esc)
		exit (0);
	else if (key == p->key.reset)
		ft_reset(*p);
	else if (key == 8)
	{
		p->color += 20;
		ft_draw_fol(*p);
	}
	else if (key == p->key.down || key == p->key.up
		|| key == p->key.left || key == p->key.right)
		ft_move(key, p);
	else if (key == p->key.i_plus || key == p->key.i_minus
		|| p->key.i_n_minus || p->key.i_n_plus)
		ft_iteration(key, p);
	return (0);
}

void	ft_move(int key, t_cplain *p)
{
	t_comp	c;

	c = ft_init_compl((p->max_re - p->min.re), (p->max_im - p->min.im));
	if (key == p->key.down)
	{
		p->max_im += c.im * 0.05;
		p->min.im += c.im * 0.05;
	}
	else if (key == p->key.up)
	{
		p->max_im -= c.im * 0.05;
		p->min.im -= c.im * 0.05;
	}
	else if (key == p->key.left)
	{
		p->min.re += c.re * 0.05;
		p->max_re += c.re * 0.05;
	}
	else if (key == p->key.right)
	{
		p->min.re -= c.re * 0.05;
		p->max_re -= c.re * 0.05;
	}
	ft_init_im_factor(p);
	ft_draw_fol(*p);
}

void	ft_iteration(int key, t_cplain *p)
{
	if (key == p->key.i_plus || key == p->key.i_n_plus)
		p->max_i *= 1.3;
	else if (key == p->key.i_minus || key == p->key.i_n_minus)
	{
		if (p->max_i > 2)
			p->max_i /= 1.3;
	}
	ft_init_im_factor(p);
	ft_draw_fol(*p);
}

void	ft_reset(t_cplain p)
{
	p.max_re = 2.0;
	p.max_i = 50;
	p.y = 0;
	p.min = ft_init_compl(-2.0, -2.0);
	p.color = 0;
	ft_init_im_factor(&p);
	ft_draw_fol(p);
}

void	ft_julia_set(char prog, t_cplain *p)
{
	if (prog == '1')
		p->k = ft_init_compl(-1.424, 0.0);
	else if (prog == '2')
		p->k = ft_init_compl(-0.412, -0.612);
	else if (prog == '3')
		p->k = ft_init_compl(0.004, -0.756);
	else if (prog == '4')
		p->k = ft_init_compl(0.408, 0.064);
	else if (prog == '5')
		p->k = ft_init_compl(-0.812, 0.216);
	else if (prog == '6')
		p->k = ft_init_compl(0.24, 0.528);
	else if (prog == '7')
		p->k = ft_init_compl(0.308, -0.008);
	else if (prog == '8')
		p->k = ft_init_compl(0.064, 0.656);
	else if (prog == '0')
		p->k = ft_init_compl(-0.604, 0.484);
}
