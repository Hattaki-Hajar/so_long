/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:14:51 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/27 00:16:04 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	wall(t_var *d, int j, int i)
{
	int h[2];
	
	d->w = mlx_xpm_file_to_image(d->mlxp, "./wall2.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->w, i * 50, j * 50);
}

void	grass(t_var *d, int j, int i)
{
	int h[2];
	
	d->g = mlx_xpm_file_to_image(d->mlxp, "./grass.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->g, i * 50, j *50);
}

void	coll(t_var *d, int j, int i)
{
	int h[2];
	
	grass(d, j, i);
	d->ct = mlx_xpm_file_to_image(d->mlxp, "./coll.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->ct, i * 50, j *50);
}

void	player(t_var *d, int j, int i)
{
	int h[2];
	
	grass(d, j, i);
	d->p = mlx_xpm_file_to_image(d->mlxp, "./player.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->p, i * 50, j *50);
}

void	portal(t_var *d, int j, int i)
{
	int h[2];
	
	grass(d, j, i);
	d->e = mlx_xpm_file_to_image(d->mlxp, "./portaal.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->e, i * 50, j *50);
}

void	open_pics(t_var *d)
{
	int		h[2];

	d->e = mlx_xpm_file_to_image(d->mlxp, "./portaal.xpm", &h[0], &h[1]);
	d->p = mlx_xpm_file_to_image(d->mlxp, "./player.xpm", &h[0], &h[1]);
	d->ct = mlx_xpm_file_to_image(d->mlxp, "./coll.xpm", &h[0], &h[1]);
	d->g = mlx_xpm_file_to_image(d->mlxp, "./grass.xpm", &h[0], &h[1]);
	d->w = mlx_xpm_file_to_image(d->mlxp, "./wall1.xpm", &h[0], &h[1]);
}
