/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:38:57 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/25 22:33:57 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_path(t_var	d)
{
	int		pos[2];
	int		e[2];
	char	**temp;
	int		check;

	temp = temp_map(d);
	find_pos(pos, d, 'P');
	find_pos(e, d, 'E');
	check = checker(pos, temp, d, 0, 0);
	// if (check_c(pos, e, d, temp, 0) == 0)
	// {
	// 	ft_putendl_fd("Invalid path", 2);
	// 	exit (6);
	// }
	if (check == 0)
	{
		ft_putendl_fd("Invalid path", 2);
		exit (6);
	}	
}

int	check_c(int	*p, int	*e, t_var	d, char	**map, int	c)
{
	int	t;
	int	i;
	int	j;

	find_pos(e, d, 'E');
	map[e[0]][e[1]] = '0';
	t = c;
	j = p[0];
	i = p[1];
	if (map[j + 1][i] == 'C' || map[j + 1][i] == '0')
	{
		if (map[j + 1][i] == 'C')
		{
			map[j][i] = '0';
			t++;
		}
		if (t == d.c)
			return (1);
		p[0] = j + 1;
		if (check_c(p, e, d, map, t))
			return (1);
	}
	else if (map[j - 1][i] == 'C' || map[j - 1][i] == '0')
	{
		if (map[j - 1][i] == 'C')
		{
			map[j][i] = '0';
			t++;
		}
		if (t == d.c)
			return (1);
		p[0] = j - 1;
		if (check_c(p, e, d, map, t))
			return (1);
	}
	else if (map[j][i + 1] == 'C' || map[j][i + 1] == '0')
	{
		if (map[j][i + 1] == 'C')
		{
			map[j][i] = '0';
			t++;
		}
		if (t == d.c)
			return (1);
		p[1] = i + 1;
		if (check_c(p, e, d, map, t))
			return (1);
	}
	else if (map[j][i - 1] == 'C' || map[j][i - 1] == '0')
	{
		if (map[j][i - 1] == 'C')
		{
			map[j][i] = '0';
			t++;
		}
		if (t == d.c)
			return (1);
		p[1] = i - 1;
		if (check_c(p, e, d, map, t))
			return (1);
	}
	return (0);
}

void	find_pos(int p[2], t_var	d, char	c)
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
			if (d.map[j][i] == c)
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

int	checker(int	p[2], char	**map, t_var	d, int dc, int	e)
{
	int	i;
	int	j;
	int	c;

	j = p[0];
	i = p[1];
	c = dc;
	dprintf(2, "here\n");
	dprintf(2, "%c, %d, %d\n", map[p[0]][p[1]], (p[0] + 1), (p[1] + 1));
	if (map[j + 1][i] == 'E' || map[j + 1][i] == '0' || map[j + 1][i] == 'C')
	{
		if (map[j + 1][i] == 'C')
			c++;
		if (map[j + 1][i] == 'E')
			e++;
		if (e == 1 && c == d.c)
			return (1);
		p[0] = j + 1;
		p[1] = i;
		if (map[j + 1][i] == '0' || map[j + 1][i] == 'C')
			map[j][i] = '1';
		if (checker(p, map, d, c, e))
			return (1);
	}
	else if (map[j - 1][i] == 'E' || map[j - 1][i] == '0' || map[j - 1][i] == 'C')
	{
		if (map[j - 1][i] == 'C')
			c++;
		if (map[j - 1][i] == 'E')
			e++;
		if (e == 1 && c == d.c)
			return (1);
		p[0] = j - 1;
		p[1] = i;
		if (map[j - 1][i] == '0' || map[j - 1][i] == 'C')
			map[j][i] = '1';
		if (checker(p, map, d, c, e))
			return (1);
	}
	if (map[j][i + 1] == 'E' || map[j][i + 1] == '0' || map[j][i + 1] == 'C')
	{
		if (map[j][i + 1] == 'C')
			c++;
		if (map[j][i + 1] == 'E')
			e++;
		if (e == 1 && c == d.c)
			return (1);
		p[0] = j;
		p[1] = i + 1;
		if (map[j][i + 1] == '0' || map[j][i + 1] == 'C')
			map[j][i] = '1';
		if (checker(p, map, d, c, e))
			return (1);
	}
	if (map[j][i - 1] == 'E' || map[j][i - 1] == '0' || map[j][i - 1] == 'C')
	{
		if (map[j][i - 1] == 'C')
			c++;
		if (map[j][i - 1] == 'E')
			e++;
		if (e == 1 && c == d.c)
			return (1);
		p[0] = j;
		p[1] = i - 1;
		if (map[j][i - 1] == '0' || map[j][i - 1] == 'C')
			map[j][i] = '1';
		if (checker(p, map, d, c, e))
			return (1);
	}
	// if (c == d.c && map[p[0]][p[1]] == 'E')
	// 	return (1);
	return (0);
}
