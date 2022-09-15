/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:44:23 by bunyodshams       #+#    #+#             */
/*   Updated: 2022/09/15 18:16:40 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft/libft.h"
#include <stdio.h>

int     find_map_x(char *map)
{
    int max;
    int fd;
    char *line;


    fd = open(map, O_RDONLY);
    line = get_next_line(fd);
    max = 0;
	while (line)
	{
        if (ft_strlen(line) > max)
            max = ft_strlen(line);
		line = get_next_line(fd);
	}
	return (max);
}

int     find_map_y(char *map)
{
    int max;
    int fd;
    char *line;


    fd = open(map, O_RDONLY);
    line = get_next_line(fd);
    max = 0;
	while (line && ++max)
	{
		line = get_next_line(fd);
	}
	return (max);
}

void    init_layout(t_game *game, char *map)
{
	int		fd;
	char	*line;
	char	**layout;
	int		i;

    game->map.xlen = find_map_x(map);
    game->map.ylen = find_map_y(map);
    printf("%d\n", game->map.xlen);
    printf("%d\n", game->map.ylen);
	i = 0;
	fd = open(map, O_RDONLY);
	layout = malloc(sizeof(char *) * (game->map.ylen + 1));
	line = get_next_line(fd);
	while (line)
	{
		layout[i] = line;
		line = get_next_line(fd);
		i++;
	}
	layout[i] = NULL;
	game->map.coord = layout;
	i = 0;
	while (game->map.coord[i])
	{
		printf("%s\n", game->map.coord[i]);
		i++;
	}
}

int main(int ac, char **av)
{
    t_game game;

    printf("ac %d\n", ac);
    init_layout(&game, av[1]);
}
