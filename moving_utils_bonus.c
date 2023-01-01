/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:30:43 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/31 22:34:36 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	right(t_var	*d)
{
	int	i;
	int	j;
	int	pos[2];

	find_pos(pos, *d);
	j = pos[0];
	i = pos[1];
	if (d->t == d->c && d->map[j][i + 1] == 'E')
	{
		d->map[j][i] = '0';
		d->move++;
		exit (0);
	}
	if (i + 1 < d->x && (d->map[j][i + 1] == '0' || d->map[j][i + 1] == 'C'))
	{
		if (d->map[j][i + 1] == 'C')
			d->t++;
		d->map[j][i + 1] = 'P';
		d->map[j][i] = '0';
		d->move++;
	}	
}

void	left(t_var	*d)
{
	int	i;
	int	j;
	int	pos[2];

	find_pos(pos, *d);
	j = pos[0];
	i = pos[1];
	if (d->t == d->c && d->map[j][i - 1] == 'E')
	{
		d->map[j][i] = '0';
		d->move++;
		exit (0);
	}
	if (i - 1 > 0 && (d->map[j][i - 1] == '0' || d->map[j][i - 1] == 'C'))
	{
		if (d->map[j][i - 1] == 'C')
			d->t++;
		d->map[j][i - 1] = 'P';
		d->map[j][i] = '0';
		d->move++;
	}
}

void	up(t_var	*d)
{
	int	i;
	int	j;
	int	pos[2];

	find_pos(pos, *d);
	j = pos[0];
	i = pos[1];
	if (d->t == d->c && d->map[j - 1][i] == 'E')
	{
		d->map[j][i] = '0';
		d->move++;
		exit (0);
	}
	if (j - 1 > 0 && (d->map[j - 1][i] == '0' || d->map[j - 1][i] == 'C'))
	{
		if (d->map[j - 1][i] == 'C')
			d->t++;
		d->map[j - 1][i] = 'P';
		d->map[j][i] = '0';
		d->move++;
	}
}

void	down(t_var	*d)
{
	int	i;
	int	j;
	int	pos[2];

	find_pos(pos, *d);
	j = pos[0];
	i = pos[1];
	if (d->t == d->c && d->map[j + 1][i] == 'E')
	{
		d->map[j][i] = '0';
		d->move++;
		exit (0);
	}
	if (j + 1 < d->y && (d->map[j + 1][i] == '0' || d->map[j + 1][i] == 'C'))
	{
		if (d->map[j + 1][i] == 'C')
			d->t++;
		d->map[j + 1][i] = 'P';
		d->map[j][i] = '0';
		d->move++;
	}
}
