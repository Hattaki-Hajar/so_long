/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:41:30 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/22 23:33:20 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	gnl(int fd)
{
	char	*line;
	int		i;
	int		len;

	line = get_next_line(fd);
	len = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (ft_strlen(line) != len)
			exit(1);
		i++;
	}
	return (i);
}

char	**get_map(int fd, int y, int x)
{
	int		fd;
	char	**map;
	int		j;
	char	*line;

	map = malloc(y * sizeof(char **));
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[j] = ft_substr(line, 0, x);
		line = get_next_line(fd);
		j++;
	}
	return (map);
}

void	map_check(char	**map, int x, int y, t_var	*d)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	d->c = 0;
	p = 0;
	e = 0;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (map[i][j] == 'p')
				p++;
			else if (map[i][j] == 'e')
				e++;
			else if (map[i][j] == 'c')
				d->c++;
			else if (map[i][j] != '1' || map[i][j] != '0')
				exit(5);
			i++;
		}
		j++;
	}
	if (d->c == 0 || p != 1 || e != 1)
		exit(6);
}



void	open_pics(t_var *d)
{
	int		h[2];

	d->w = mlx_xpm_file_to_image(d->mlxp, "./utils/wall.xpm", &h[0], &h[1]);
	d->e = mlx_xpm_file_to_image(d->mlxp, "./utils/exit.xpm", &h[0], &h[1]);
	d->p = mlx_xpm_file_to_image(d->mlxp, "./utils/player.xpm", &h[0], &h[1]);
	d->c = mlx_xpm_file_to_image(d->mlxp, "./utils/coll.xpm", &h[0], &h[1]);
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
				mlx_put_image_to_window(d.mlxp, d.window, d.c, h[0], h[1]);
			if (line[i] == 'E')
				mlx_put_image_to_window(d.mlxp, d.window, d.e, h[0], h[1]);
			if (line[i] == 'P')
				mlx_put_image_to_window(d.mlxp, d.window, d.p, h[0], h[1]);
			i++;
			h[1] += 30;
		}
		line = get_next_line(fd);
		h[1] += 30;
	}
}
