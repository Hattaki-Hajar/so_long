/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:17:29 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/27 00:37:54 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	right(t_var	*d)
{
	int	i;
	int	j;
	int	pos[2];

	find_pos(pos, *d);
	j = pos[0];
	i = pos[1];
	if (i + 1 < d->x && (d->map[j][i + 1] == '0' || d->map[j][i + 1] == 'C'))
	{
		pos[0] = j;
		pos[1] = i + 1;
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
	if (i - 1 > 0 && (d->map[j][i - 1] == '0' || d->map[j][i - 1] == 'C'))
	{
		pos[0] = j;
		pos[1] = i - 1;
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
	if (j - 1 > 0 && (d->map[j - 1][i] == '0' || d->map[j - 1][i] == 'C'))
	{
		pos[0] = j - 1;
		pos[1] = i;
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
	if (j + 1 < d->y && (d->map[j + 1][i] == '0' || d->map[j + 1][i] == 'C'))
	{
		pos[0] = j + 1;
		pos[1] = i;
	}
}
