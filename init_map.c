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

void    init_layout(t_game *game, char *map)
{
	int		fd;
	char	*line;
	char	**layout;
	int		i;
    int     x;

    x = find_map_x(map);
    game->map.xlen = x;
    printf("%d\n", game->map.xlen);
    exit (1);
	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	// layout = malloc(sizeof(char *) * (y + 1));
	while (line)
	{
		layout[i] = line;
		i++;
		line = get_next_line(fd);
	}
	layout[i] = NULL;
}

int main(int ac, char **av)
{
    t_game game;

    printf("ac %d", ac);
    init_layout(&game, av[1]);
}
