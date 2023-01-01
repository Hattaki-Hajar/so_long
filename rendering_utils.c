/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:14:51 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/29 23:42:55 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	wall(t_var *d, int j, int i)
{
	mlx_put_image_to_window(d->mlxp, d->window, d->w, i * 50, j * 50);
}

void	grass(t_var *d, int j, int i)
{
	mlx_put_image_to_window(d->mlxp, d->window, d->g, i * 50, j * 50);
}

void	coll(t_var *d, int j, int i)
{
	grass(d, j, i);
	mlx_put_image_to_window(d->mlxp, d->window, d->ct, i * 50, j * 50);
}

void	player(t_var *d, int j, int i)
{
	grass(d, j, i);
	mlx_put_image_to_window(d->mlxp, d->window, d->p, i * 50, j * 50);
}

void	portal(t_var *d, int j, int i)
{
	grass(d, j, i);
	mlx_put_image_to_window(d->mlxp, d->window, d->e, i * 50, j * 50);
}
