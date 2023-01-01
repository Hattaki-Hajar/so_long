/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:25:09 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/31 22:52:19 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include<mlx.h>
# include<stdio.h>
# include"../libft/get_next_line.h"
# include"../libft/libft.h"

typedef struct s_var
{
	void	*mlxp;
	void	*window;
	char	**map;
	void	*e;
	void	*p;
	void	*g;
	void	*ct[3];
	void	*w;
	int		x;
	int		y;
	int		c;
	int		t;
	int		move;
	int		i;
	int		tmr;
}	t_var;
typedef struct s_path
{
	int	e;
	int	c_nbr;
}	t_path;
/*	map	*/
int		get_x(char	*file);
int		get_y(char	*file);
void	map_check1(t_var	*d);
char	**get_map(int fd, int y, int x);
void	find_pos(int	*p, t_var	d);
void	check_borders(t_var	d);
void	map_check2(t_var *d);
/*	path	*/
void	final_path(t_var	d);
/*	rendering	*/
void	open_pics(t_var	*d);
void	coll(t_var *d, int j, int i);
void	wall(t_var *d, int j, int i);
void	grass(t_var *d, int j, int i);
void	portal(t_var *d, int j, int i);
void	player(t_var *d, int j, int i);
void	print_move(t_var *d);
/*	moving	*/
void	right(t_var	*d);
void	left(t_var	*d);
void	up(t_var	*d);
void	down(t_var	*d);
/*	error handling	*/
void	ft_error(char *str);
int		check_arg(char	*arg);

#endif