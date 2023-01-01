/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:31:33 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/31 22:56:09 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

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
	printf("%d\n", d->i);
	if (d->tmr > 60)
	{
		d->i = d->i + 1;
		d->tmr = 0;
	}
	if(d->i > 1)
	{
		d->i = 0;
	}
	mlx_put_image_to_window(d->mlxp, d->window, d->ct[d->i], i * 50, j * 50);
	d->tmr++;
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
