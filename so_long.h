/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:40:03 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/24 21:12:38 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_var
{
	void	*mlxp;
	void	*window;
	char	**map;
	void	*e;
	void	*p;
	void	*ct;
	void	*w;
	int		x;
	int		y;
	int		c;
}	t_var;

# include<mlx.h>
#include <stdio.h>
# include"./libft/get_next_line.h"
# include"./libft/libft.h"

int		gnl(int fd);
void	open_pics(t_var	*d);
void	rendring(int fd, t_var d);
char	**get_map(int fd, int	y, int	x);
void	map_check(t_var	*d);
void	player_pos(int p[2], t_var	d);
char	**temp_map(t_var	d);
int		checker(int	p[2], char	**map, t_var	d);
void	check_path(t_var	d);
void	check_borders(t_var	d);
void	final_check(t_var	d);

#endif