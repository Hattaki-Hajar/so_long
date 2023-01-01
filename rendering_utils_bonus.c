/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:31:33 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/01 23:35:50 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	wall(t_var *d, int j, int i)
{
	int	h[2];

	d->w = mlx_xpm_file_to_image(d->mlxp, "./utils/rocks2.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->w, i * 50, j * 50);
	mlx_destroy_image(d->mlxp, d->w);
}

void	grass(t_var *d, int j, int i)
{
	int	h[2];

	d->g = mlx_xpm_file_to_image(d->mlxp, "./utils/grass0.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->g, i * 50, j * 50);
	mlx_destroy_image(d->mlxp, d->g);
}

void	coll(t_var *d, int j, int i)
{
	int	h[2];
	int	r;

	r = d->c - d->t;
	grass(d, j, i);
	if (d->tmr > r * 5)
	{
		d->i = d->i + 1;
		d->tmr = 0;
	}
	if (d->i > 1)
		d->i = 0;
	d->ct[0] = mlx_xpm_file_to_image(d->mlxp, "./utils/c0.xpm", &h[0], &h[1]);
	d->ct[1] = mlx_xpm_file_to_image(d->mlxp, "./utils/c1.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->ct[d->i], i * 50, j * 50);
	mlx_destroy_image(d->mlxp, d->ct[0]);
	mlx_destroy_image(d->mlxp, d->ct[1]);
	d->tmr++;
}

void	player(t_var *d, int j, int i)
{
	int	h[2];

	grass(d, j, i);
	d->p = mlx_xpm_file_to_image(d->mlxp, "./utils/player.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->p, i * 50, j * 50);
	mlx_destroy_image(d->mlxp, d->p);
}

void	portal(t_var *d, int j, int i)
{
	int	h[2];

	grass(d, j, i);
	// if (d->t != d->c)
	// 	d->e = mlx_xpm_file_to_image(d->mlxp, "./utils/portal2.xpm", &h[0], &h[1]);
	// else
		d->e = mlx_xpm_file_to_image(d->mlxp, "./utils/exit.xpm", &h[0], &h[1]);
	mlx_put_image_to_window(d->mlxp, d->window, d->e, i * 50, j * 50);
	mlx_destroy_image(d->mlxp, d->e);
}
