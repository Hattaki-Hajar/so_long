/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:41:30 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/24 21:15:17 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	gnl(int fd)
{
	char	*line;
	int		i;
	size_t		len;

	line = get_next_line(fd);
	len = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (ft_strlen(line) != len)
		{
			ft_putendl_fd("Invalid map", 2);
			exit(1);
		}
			
		i++;
	}
	return (i);
}

char	**get_map(int fd, int	y, int	x)
{
	char	**map;
	int		j;
	char	*line;

	map = malloc(y * sizeof(char *));
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

void	map_check(t_var	*d)
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
	
	dprintf(2,"%s\n",d->map[0]);
	while (j < d->y)
	{
		i = 0;
		while (i < d->x)
		{
			dprintf(2, ":%c:\n",d->map[i][j]);
			if (d->map[i][j] == 'P')
				p++;
			else if (d->map[i][j] == 'E')
				e++;
			else if (d->map[i][j] == 'C')
				d->c++;
			else if (d->map[i][j] != '1' && d->map[i][j] != '0')
				exit(5);
			i++;
		}
		j++;
	}
	if (d->c == 0 || p != 1 || e != 1)
	{
		dprintf(2, "C= %d P= %d E= %d\n", d->c,p,e);	
		exit(23);
	}
}

void	check_borders(t_var	d)
{
	int	i;

	i = 0;
	while (d.map[1])
	{
		if (d.map[1][i] != '1')
			exit(3);
		i++;
	}
	i = 0;
	while (d.map[d.y - 1])
	{
		if (d.map[d.y - 1][i] != '1')
			exit(3);
		i++;
	}
	i = 0;
	while (i < d.y)
	{
		if (d.map[i][0] != '1' || d.map[i][d.x - 1] != '1')
			exit(4);
		i++;
	}
}

void	final_check(t_var	d)
{
	map_check(&d);
	check_borders(d);
}