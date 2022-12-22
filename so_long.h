/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:40:03 by hhattaki          #+#    #+#             */
/*   Updated: 2022/12/22 23:28:25 by hhattaki         ###   ########.fr       */
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
	void	*c;
	void	*w;
	int		x;
	int		y;
	int		c;
}	t_var;

# include<mlx.h>
# include"./libft/get_next_line.h"
# include"./libft/libft.h"

int		gnl(int fd);
void	open_pics(t_var	*d);
void	rendring(int fd, t_var d);
char	**get_map(int fd, int y, int x);
void	map_check(char	**map, int x, int y)

#endif