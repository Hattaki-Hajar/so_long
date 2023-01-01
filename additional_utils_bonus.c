/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:00:27 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/01 21:14:48 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (-1);
}

void	print_move(t_var *d)
{
	char	*str;
	char	*nbr;
	char	*final;

	str = ft_strdup("number of moves = ");
	nbr = ft_itoa(d->move);
	final = ft_strjoin(str, nbr);
	free (nbr);
	free(str);
	mlx_string_put(d->mlxp, d->window, 0, 0, 0x000000, final);
	free(final);
}

int	check_arg(char	*arg)
{
	char	*temp;

	temp = ft_strrchr(arg, '.');
	if (!temp)
		return (0);
	if (ft_strlen(temp) != 4)
		return (0);
	if (ft_strncmp(".ber", temp, 4))
		return (0);
	return (1);
}

void	map_check2(t_var *d)
{
	int	i;
	int	e;
	int	j;
	int	p;

	d->t = 0;
	e = 0;
	p = 0;
	j = 0;
	while (j < d->y)
	{
		i = 0;
		while (i < d->x)
		{
			if (d->map[j][i] == 'P')
				p++;
			else if (d->map[j][i] == 'E')
				e++;
			i++;
		}
		j++;
	}
	if (e != 1 || p != 1)
		ft_error("Error\nInvalid map: Invalid number of elements");
}
