#include "./includes/fractol.h"

t_comp	ft_init_compl(double re, double im)
{
	t_comp	c;

	c.re = re;
	c.im = im;
	return (c);
}

t_data	ft_init_img(void *mlx)
{
	t_data	img;

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.line_length, &img.end);
	return (img);
}

t_cplain	ft_init_plain(void)
{
	t_cplain	p;

	p.min = ft_init_compl(-2.0, -2.0);
	p.k = ft_init_compl(-0.4, 0.6);
	p.max_re = 2.0;
	p.max_i = 50;
	p.color = 0;
	p.y = 0;
	ft_init_im_factor(&p);
	return (p);
}

t_cplain	ft_init_default(void)
{
	t_cplain	p;

	p = ft_init_plain();
	ft_init_keys(&p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, "fractol");
	p.img = ft_init_img(p.mlx);
	return (p);
}

void	ft_init_keys(t_cplain *p)
{
	p->key.i_n_minus = 78;
	p->key.i_n_plus = 69;
	p->key.down = 125;
	p->key.up = 126;
	p->key.left = 123;
	p->key.right = 124;
	p->key.i_plus = 24;
	p->key.i_minus = 27;
	p->key.reset = 15;
	p->key.esc = 53;
}
