/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:18:04 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/27 00:29:11 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void printmap(char **map)
{
	int i = 0;
	while (map[i])
	{
		printf("%s\n",map[i]);
		i++;
	}
	
}
void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (-1);
}
int ft_key(int key,t_var *d)
{
	if (key == 53)
		exit(0);
	if (key == 126)
		up(*d);
	if (key == 125)
		down(*d);
	if (key == 124)
		right(*d);
	if (key == 123)
		left(*d);
	printf("%d\n",key);
	return(d->x);
}

int	rendering(t_var	*d)
{
	int		i;
	int		j;

	j = 0;
	while (j < d->y)
	{
		i = 0;
		
		while (d->map[j][i])
		{
			if (d->map[j][i] == '1')
				wall(d, j, i);
			if (d->map[j][i] == 'C')
				coll(d, j, i);
			if (d->map[j][i] == 'E')
				portal(d, j, i);
			if (d->map[j][i] == 'P')
				player(d, j, i);
			if (d->map[j][i] == '0')
				grass(d, j, i);
			i++;
		}
		j++;
	}
	return(0);
}

int	main(int ac, char	**av)
{
	t_var	d;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd == -1)
		ft_error("Invalid arguments");
	d.x = get_x(av[1]);
	d.y = get_y(av[1]);
	d.map = get_map(fd, d.y, d.x);
	map_check(&d);
	check_borders(d);
	final_path(d);
	d.mlxp = mlx_init();
	d.window = mlx_new_window(d.mlxp, (d.x * 50), (d.y * 50), "so_long");
	open_pics(&d);
	rendering(&d);
	mlx_loop_hook(d.mlxp, &rendering, &d);
	close(fd);
	mlx_key_hook(d.window,&ft_key,&d);
	mlx_loop(d.mlxp);
}
