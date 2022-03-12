#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <mlx.h>
# include <math.h>

# define HEIGHT 1000
# define WIDTH 1000

typedef struct s_comp
{
	double	re;
	double	im;
}				t_comp;

typedef struct s_color
{
	double	t;
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		end;
}				t_data;

typedef struct s_keys
{
	int	left;
	int	right;
	int	up;
	int	down;
	int	i_plus;
	int	i_minus;
	int	reset;
	int	i_n_plus;
	int	i_n_minus;
	int	esc;
}				t_keys;

typedef struct s_cplane
{
	void		*mlx;
	void		*win;
	double		max_re;
	double		max_im;
	int			color;
	int			max_i;
	int			i;
	int			y;
	int			x;
	int			number_fractol;
	t_comp		min;
	t_comp		factor;
	t_comp		z;
	t_comp		c;
	t_comp		k;
	t_data		img;
	t_keys		key;
}				t_cplain;

t_comp		ft_init_compl(double re, double im);
t_cplain	ft_init_plain(void);
t_data		ft_init_img(void *mlx);
t_cplain	ft_init_default(void);
void		ft_init_keys(t_cplain *p);
void		ft_reset(t_cplain p);
int			press_key(int key, t_cplain *p);
void		ft_fol(t_cplain p);
void		ft_move(int key, t_cplain *p);
void		ft_draw_fol(t_cplain p);
void		ft_iteration(int key, t_cplain *p);
int			ft_julia_mn(int x, int y, t_cplain *p);
void		ft_mandelbrot(t_cplain *p);
void		ft_burning_ship(t_cplain *p);
void		ft_print_info(void);
void		my_pixel_put(t_data *data, int x, int y, int color);
int			ft_create_rgb(double i, double max_i, int color);
void		ft_julia(t_cplain *p);
int			ft_zoom(int key, int x, int y, t_cplain *p);
void		ft_init_im_factor(t_cplain *p);
int			ft_fractal_is(char *str);
void		ft_julia_set(char prog, t_cplain *p);

#endif
