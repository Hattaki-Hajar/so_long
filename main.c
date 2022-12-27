/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:18:04 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/27 22:42:50 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (-1);
}

int	ft_key(int key, t_var *d)
{
	if (key == 53)
		exit(0);
	if (key == 13 || key == 126)
		up(d);
	if (key == 1 || key == 125)
		down(d);
	if (key == 2 ||key == 124)
		right(d);
	if (key == 0 || key == 123)
		left(d);
	return (d->x);
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
	return (0);
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
	close(fd);
	d.mlxp = mlx_init();
	open_pics(&d);
	d.window = mlx_new_window(d.mlxp, (d.x * 50), (d.y * 50), "so_long");
	mlx_loop_hook(d.mlxp, &rendering, &d);
	mlx_key_hook(d.window, &ft_key, &d);
	// system("leaks so_long");
	mlx_loop(d.mlxp);
}
