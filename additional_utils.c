/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:28:44 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/29 16:42:29 by hhattaki         ###   ########.fr       */
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

	d->g = mlx_xpm_file_to_image(d->mlxp, "./utils/coolwall.xpm", &h[0], &h[1]);
	d->e = mlx_xpm_file_to_image(d->mlxp, "./utils/portaal.xpm", &h[0], &h[1]);
	d->p = mlx_xpm_file_to_image(d->mlxp, "./utils/dan.xpm", &h[0], &h[1]);
	d->ct = mlx_xpm_file_to_image(d->mlxp, "./utils/coll.xpm", &h[0], &h[1]);
	d->w = mlx_xpm_file_to_image(d->mlxp, "./utils/wall2.xpm", &h[0], &h[1]);
}
