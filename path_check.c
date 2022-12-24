/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:38:57 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/24 19:50:34 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	check_path(t_var	d)
{
	int		pos[2];
	char	**temp;

	player_pos(pos, d);
	temp = temp_map(d);
	if (checker(pos, temp, d) == 0)
	{
		ft_putendl_fd("Invalid path", 2);
		exit (6);
	}	
}

void	player_pos(int p[2], t_var	d)
{
	int	i;
	int	j;

	j = 0;
	p[0] = 0;
	p[1] = 0;
	while (j < d.y)
	{
		i = 0;
		while (i < d.x)
		{
			if (d.map[j][i] == 'P')
			{
				p[0] = j;
				p[1] = i;
			}
			i++;
		}
		j++;
	}
	if (i == d.x && j == d.y && !p[0])
		exit(7);
}

char	**temp_map(t_var	d)
{
	char	**temp;
	int		i;
	
	temp = ft_calloc(d.y, sizeof(char *));
	i = 0;
	while (i < d.y)
	{
		temp[i] = ft_strdup(d.map[i]);
		i++;
	}
	return (temp);
}

int	checker(int	p[2], char	**map, t_var	d)
{
	int	i;
	int	j;
	int	c;

	i = p[0];
	j = p[1];
	c = 0;
	if (map[p[0]][p[1]] != 'E' && (map[i + 1][j] == '0' || map[i + 1][j] == 'C'))
	{
		if (map[i + 1][j] == 'C')
			c++;
		p[0] = i + 1;
		p[1] = j;
		map[i][j] = '1';
		checker(p, map, d);
	}
	if (map[p[0]][p[1]] != 'E' && (map[i - 1][j] == '0' || map[i - 1][j] == 'C'))
	{
		if (map[i - 1][j] == 'C')
			c++;
		p[0] = i - 1;
		p[1] = j;
		map[i][j] = '1';
		checker(p, map, d);
	}
	if (map[p[0]][p[1]] != 'E' && (map[i][j + 1] == '0' || map[i][j + 1] == 'C'))
	{
		if (map[i][j + 1] == 'C')
			c++;
		p[0] = i;
		p[1] = j + 1;
		map[i][j] = '1';
		checker(p, map, d);
	}
	if (map[p[0]][p[1]] != 'E' && (map[i][j - 1] == '0' || map[i][j - 1] == 'C'))
	{
		if (map[i][j - 1] == 'C')
			c++;
		p[0] = i;
		p[1] = j - 1;
		map[i][j] = '1';
		checker(p, map, d);
	}
	if (c == d.c && map[p[0]][p[1]] == 'E')
		return (1);
	return (0);
}
