/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:18:04 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/22 22:51:53 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include<stdio.h>

int main(int ac, char	**av)
{
	t_var	d;
	// int		h[2];
	// // int		y[2];
	// void	*image;
	// void	*image2;
	char	*line;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	exit(1);
	d.x = gnl(fd) - 1;
	line = get_next_line(fd);
	d.y = 0;
	while (line)
	{
		line = get_next_line(fd);
		d.y++;
	}
	close(fd);
	d.map = get_map(fd, d.y, d.x);
	d.mlxp = mlx_init();
	// open_pics(&d);
	// rendering(d);
	// d.window = mlx_new_window(d.mlxp, 1440, 720, "so_long");
	// image = mlx_xpm_file_to_image(d.mlxp, "./yor.xpm", &h[0], &h[1]);
	// h[0] += 720;
	// image2 = mlx_xpm_file_to_image(d.mlxp, "./p.xpm", &h[0], &h[1]);
	// mlx_put_image_to_window(d.mlxp, d.window, image, 0, 0);
	// mlx_put_image_to_window(d.mlxp, d.window, image2, 720, 0);
	mlx_loop(d.mlxp);
}