/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:19:37 by lmother           #+#    #+#             */
/*   Updated: 2021/05/02 20:24:38 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i <= (int) ft_strlen(s))
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}