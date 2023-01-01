/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:28:44 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/01 20:05:20 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (-1);
}

void	open_pics(t_var	*d)
{
	int	h[2];

	d->g = mlx_xpm_file_to_image(d->mlxp, "./utils/grass0.xpm", &h[0], &h[1]);
	d->e = mlx_xpm_file_to_image(d->mlxp, "./utils/portaal.xpm", &h[0], &h[1]);
	d->p = mlx_xpm_file_to_image(d->mlxp, "./utils/player.xpm", &h[0], &h[1]);
	d->ct = mlx_xpm_file_to_image(d->mlxp, "./utils/c0.xpm", &h[0], &h[1]);
	d->w = mlx_xpm_file_to_image(d->mlxp, "./utils/rocks2.xpm", &h[0], &h[1]);
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
