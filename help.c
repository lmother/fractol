#include "./includes/fractol.h"

void	ft_print_info(void)
{
	ft_putendl_fd("", 1);
	ft_putendl_fd("Specify the fractal number in the parameters:", 1);
	ft_putendl_fd(" Example: >./fractol [1 ... 3]", 1);
	ft_putendl_fd(" Example only for Julia: >./fractol [1 ... 3] [1 ... 8]", 1);
	ft_putendl_fd(" 1 - Mandelbrot", 1);
	ft_putendl_fd(" 2 - Julia", 1);
	ft_putendl_fd(" 3 - Perpedicular Burning Ship", 1);
}

int	ft_fractal_is(char *str)
{
	if (ft_strlen(str) == 1
		&& str[0] == '1')
		return (1);
	else if (ft_strlen(str) == 1
		&& str[0] == '2')
		return (2);
	else if (ft_strlen(str) == 1
		&& str[0] == '3')
		return (3);
	return (0);
}
