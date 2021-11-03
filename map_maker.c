/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:07:37 by nortolan          #+#    #+#             */
/*   Updated: 2021/11/03 18:44:44 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(char block, t_map *vars, int x, int y)
{
	if (block != '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->floor, x, y);
	if (block == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall, x, y);
	if (block == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player, x, y);
		vars->ppos[0] = x;
		vars->ppos[1] = y;
	}
	if (block == 'E')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->exit, x, y);
	if (block == 'C')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->collect, x, y);
}

void	print_map(t_map *vars, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->height)
	{
		j = -1;
		x = 0;
		while (vars->map[i][++j] != '\n')
		{
			put_img(vars->map[i][j], vars, x, y);
			x += 32;
		}
		y += 32;
	}
}

void	map_open(t_map *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx,
			vars->width * 32, vars->height * 32, "so_long");
	img_get(vars);
	print_map(vars, 0, 0);
	mlx_hook(vars->mlx_win, 17, 1L << 17, red_x, vars);
	mlx_key_hook(vars->mlx_win, key_hooks, vars);
	mlx_loop(vars->mlx);
}

void	second_read(char *file, t_map *vars)
{
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		fail();
	else
	{
		vars->map = malloc(sizeof(char *) * (vars->height));
		if (vars->map == NULL)
			fail();
		i = 0;
		vars->map[i] = get_next_line(fd);
		if (vars->map[i++] == NULL)
			fail();
		while (i < vars->height)
			vars->map[i++] = get_next_line(fd);
		if (top_and_bottom(vars))
			fail();
		map_open(vars);
		mega_free(vars);
	}
	close(fd);
}
