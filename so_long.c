/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nortolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:07:26 by nortolan          #+#    #+#             */
/*   Updated: 2021/11/03 16:38:48 by nortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	top_and_bottom(t_map *vars)
{
	int	i;

	i = -1;
	while (vars->map[0][++i] != '\n')
	{
		if (vars->map[0][i] != '1')
			return (1);
	}
	i = -1;
	while (vars->map[vars->height - 1][++i] != '\n')
	{
		if (vars->map[vars->height - 1][i] != '1')
			return (1);
	}
	return (0);
}

int	lines_check(char *s, t_map *vars)
{
	int	i;

	i = -1;
	if (s[0] != '1' || s[ft_strlen(s) - 2] != '1')
		return (1);
	while (s[++i] != '\n')
	{
		if (s[i] == 'P')
			vars->p_char += 1;
		else if (s[i] == 'E')
			vars->e_char += 1;
		else if (s[i] == 'C')
			vars->c_char += 1;
		else if (s[i] != '1' && s[i] != '0')
			return (1);
	}
	if (vars->width == -1)
		vars->width = i;
	if (vars->width != -1 && vars->width != i)
		return (1);
	return (0);
}

void	get_lines(t_map *vars, int fd)
{
	char	*s;

	*vars = vars_init(vars);
	s = get_next_line(fd);
	if (!s)
		fail();
	while (s)
	{
		vars->height += 1;
		if (lines_check(s, vars))
			fail();
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	if (vars->width == vars->height || vars->p_char != 1
		|| vars->e_char != 1 || vars->c_char < 1)
		fail();
}

void	map_read(char *file)
{
	t_map	vars;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		fail();
	else
		get_lines(&vars, fd);
	close(fd);
	second_read(file, &vars);
}

/*void	leaks(void)
{
	system("leaks -q so_long");
}*/
/*atexit(leaks);*/

int	main(int argc, char **argv)
{
	char	*format_check;

	if (argc == 2)
	{
		format_check = ft_substr(argv[1],
				ft_strlen(argv[1]) - 3, ft_strlen(argv[1]));
		if (ft_strncmp(format_check, "ber", 4))
			fail();
		map_read(argv[1]);
	}
	else
		fail();
	return (0);
}
