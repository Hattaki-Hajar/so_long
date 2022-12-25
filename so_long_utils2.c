/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:14:51 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/25 16:41:02 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	open_pics(t_var *d)
{
	int		h[2];

	d->w = mlx_xpm_file_to_image(d->mlxp, "./utils/wall.xpm", &h[0], &h[1]);
	d->e = mlx_xpm_file_to_image(d->mlxp, "./utils/exit.xpm", &h[0], &h[1]);
	d->p = mlx_xpm_file_to_image(d->mlxp, "./utils/player.xpm", &h[0], &h[1]);
	d->ct = mlx_xpm_file_to_image(d->mlxp, "./utils/coll.xpm", &h[0], &h[1]);
}

void	rendering(int fd, t_var	d)
{
	int		i;
	char	*line;
	int		h[2];

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		h[0] = 0;
		while (line[i])
		{
			if (line[i] == '1')
				mlx_put_image_to_window(d.mlxp, d.window, d.w, h[0], h[1]);
			if (line[i] == 'C')
				mlx_put_image_to_window(d.mlxp, d.window, d.ct, h[0], h[1]);
			if (line[i] == 'E')
				mlx_put_image_to_window(d.mlxp, d.window, d.e, h[0], h[1]);
			if (line[i] == 'P')
				mlx_put_image_to_window(d.mlxp, d.window, d.p, h[0], h[1]);
			i++;
			h[1] += 30;
		}
		free(line);
		line = get_next_line(fd);
		h[1] += 30;
	}
}
