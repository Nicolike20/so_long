/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:59:53 by nortolan          #+#    #+#             */
/*   Updated: 2021/11/02 12:05:17 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fail(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	mega_free(t_map *vars)
{
	int	i;

	i = 0;
	while (i < vars->height)
		free(vars->map[i++]);
	free(vars->map);
}

int	red_x(t_map *vars)
{
	mega_free(vars);
	exit(0);
	return (0);
}

void	img_get(t_map *vars)
{
	int	size;

	size = 32;
	vars->player = mlx_xpm_file_to_image(vars->mlx, "./img/player.xpm",
			&size, &size);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./img/exit.xpm",
			&size, &size);
	vars->collect = mlx_xpm_file_to_image(vars->mlx, "./img/collect.xpm",
			&size, &size);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "./img/floor.xpm",
			&size, &size);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm",
			&size, &size);
}

t_map	vars_init(t_map *vars)
{
	vars->p_char = 0;
	vars->c_char = 0;
	vars->e_char = 0;
	vars->width = -1;
	vars->height = 0;
	vars->map = NULL;
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->img = NULL;
	vars->picked = 0;
	vars->moves = 1;
	return (*vars);
}
