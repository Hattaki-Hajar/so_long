/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:40:03 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/27 00:36:28 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<mlx.h>
# include <stdio.h>
# include"./libft/get_next_line.h"
# include"./libft/libft.h"

typedef struct s_var
{
	void	*mlxp;
	void	*window;
	char	**map;
	void	*e;
	void	*p;
	void	*g;
	void	*ct;
	void	*w;
	int		x;
	int		y;
	int		c;
}	t_var;

typedef struct s_path
{
	int	e;
	int	c_nbr;
}	t_path;

int		get_x(char	*file);
int		get_y(char	*file);
void	open_pics(t_var	*d);
int		rendring(t_var *d);
char	**get_map(int fd, int y, int x);
void	map_check(t_var	*d);
void	find_pos(int	*p, t_var	d);
void	final_path(t_var	d);
void	check_borders(t_var	d);
void	final_check(t_var	d);
void	right(t_var	*d);
void	left(t_var	*d);
void	up(t_var	*d);
void	down(t_var	*d);
void	ft_error(char *str);
void	coll(t_var *d, int j, int i);
void	wall(t_var *d, int j, int i);
void	portal(t_var *d, int j, int i);
void	grass(t_var *d, int j, int i);
void	player(t_var *d, int j, int i);



#endif