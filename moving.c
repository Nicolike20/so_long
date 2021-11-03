/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:06:20 by nortolan          #+#    #+#             */
/*   Updated: 2021/11/02 12:09:09 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_map *vars)
{
	char	c;

	c = vars->map[vars->ppos[1] / 32][vars->ppos[0] / 32 - 1];
	if (c == 'E' && vars->picked == vars->c_char)
	{
		mega_free(vars);
		exit(0);
	}
	if (c == '0' || c == 'C')
	{
		if (c == 'C')
			vars->picked += 1;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor,
			vars->ppos[0], vars->ppos[1]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor,
			vars->ppos[0] - 32, vars->ppos[1]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player,
			vars->ppos[0] - 32, vars->ppos[1]);
		vars->map[vars->ppos[1] / 32][vars->ppos[0] / 32] = '0';
		vars->ppos[0] -= 32;
		printf("Moves: %d\n", vars->moves++);
	}
}

void	right(t_map *vars)
{
	char	c;

	c = vars->map[vars->ppos[1] / 32][vars->ppos[0] / 32 + 1];
	if (c == 'E' && vars->picked == vars->c_char)
	{
		mega_free(vars);
		exit(0);
	}
	if (c == '0' || c == 'C')
	{
		if (c == 'C')
			vars->picked += 1;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor,
			vars->ppos[0], vars->ppos[1]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor,
			vars->ppos[0] + 32, vars->ppos[1]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player,
			vars->ppos[0] + 32, vars->ppos[1]);
		vars->map[vars->ppos[1] / 32][vars->ppos[0] / 32] = '0';
		vars->ppos[0] += 32;
		printf("Moves: %d\n", vars->moves++);
	}
}

void	up(t_map *vars)
{
	char	c;

	c = vars->map[vars->ppos[1] / 32 - 1][vars->ppos[0] / 32];
	if (c == 'E' && vars->picked == vars->c_char)
	{
		mega_free(vars);
		exit(0);
	}
	if (c == '0' || c == 'C')
	{
		if (c == 'C')
			vars->picked += 1;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor,
			vars->ppos[0], vars->ppos[1]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor,
			vars->ppos[0], vars->ppos[1] - 32);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player,
			vars->ppos[0], vars->ppos[1] - 32);
		vars->map[vars->ppos[1] / 32][vars->ppos[0] / 32] = '0';
		vars->ppos[1] -= 32;
		printf("Moves: %d\n", vars->moves++);
	}
}

void	down(t_map *vars)
{
	char	c;

	c = vars->map[vars->ppos[1] / 32 + 1][vars->ppos[0] / 32];
	if (c == 'E' && vars->picked == vars->c_char)
	{
		mega_free(vars);
		exit(0);
	}
	if (c == '0' || c == 'C')
	{
		if (c == 'C')
			vars->picked += 1;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor,
			vars->ppos[0], vars->ppos[1]);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor,
			vars->ppos[0], vars->ppos[1] + 32);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player,
			vars->ppos[0], vars->ppos[1] + 32);
		vars->map[vars->ppos[1] / 32][vars->ppos[0] / 32] = '0';
		vars->ppos[1] += 32;
		printf("Moves: %d\n", vars->moves++);
	}
}

int	key_hooks(int key, t_map *vars)
{
	if (key == 53)
	{
		mega_free(vars);
		exit(0);
	}
	if (key == 0)
		left(vars);
	if (key == 1)
		down(vars);
	if (key == 2)
		right(vars);
	if (key == 13)
		up(vars);
	return (0);
}
