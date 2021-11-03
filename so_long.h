/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:08:13 by nortolan          #+#    #+#             */
/*   Updated: 2021/11/02 12:39:11 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct s_map
{
	int		p_char;
	int		e_char;
	int		c_char;
	int		width;
	int		height;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		line_length;
	void	*player;
	void	*exit;
	void	*collect;
	void	*floor;
	void	*wall;
	int		ppos[2];
	int		picked;
	int		moves;
}t_map;

void	fail(void);
void	mega_free(t_map *vars);
int		red_x(t_map *vars);
void	img_get(t_map *vars);
t_map	vars_init(t_map *vars);
int		key_hooks(int key, t_map *vars);
void	second_read(char *file, t_map *vars);
int		top_and_bottom(t_map *vars);
#endif
