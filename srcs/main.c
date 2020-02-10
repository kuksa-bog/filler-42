/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:25:14 by bkuksa            #+#    #+#             */
/*   Updated: 2019/05/13 11:20:51 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_map		map;
	t_player	pl;

	ft_initialization1(&map, &pl);
	ft_player(&pl, &map);
	while (1)
	{
		ft_initialization2(&pl);
		ft_initialization3(&map, &pl);
		ft_size_map(&map);
		ft_cut(&map, &pl);
		ft_tet_place(&map, &pl);
		ft_search_x0(&pl, &map);
		ft_free(&map);
		free(pl.zenna);
		ft_write(&pl);
		if (pl.x == -1000 && pl.y == -1000 && pl.x2 == -1000 && pl.y2 == -1000)
			break ;
	}
	return (0);
}

void	ft_initialization1(t_map *map, t_player *pl)
{
	pl->n = 0;
	map->fd = FD;
	pl->bog = 0;
	pl->dev = 0;
	pl->z1 = -1;
}

void	ft_initialization2(t_player *pl)
{
	pl->k = 100000000;
	pl->k1 = 100000000;
	pl->xu = 0;
	pl->yu = 0;
	pl->x = -1000;
	pl->y = -1000;
	pl->yl = 0;
	pl->xl = 0;
	pl->xt = 0;
	pl->yt = 0;
	pl->xp = 0;
	pl->yp = 0;
	pl->error = 0;
	pl->n = 0;
	pl->i = 0;
	pl->er = 0;
	pl->tet1 = 0;
	pl->tet2 = 0;
	pl->zenna = NULL;
}

void	ft_initialization3(t_map *map, t_player *pl)
{
	pl->a1 = 0;
	pl->a2 = 0;
	pl->a3 = 0;
	pl->a4 = 0;
	pl->a5 = 0;
	pl->h = 8;
	map->size_map_y = 0;
	map->size_map_x = 0;
	map->size_tet_y = 0;
	map->size_tet_x = 0;
	map->i = 0;
	map->x = -1;
	map->y = -1;
}

void	ft_initial_alg(t_player *pl, int i)
{
	if (i == 0)
	{
		pl->z = -2;
		pl->f = -2;
		pl->v = 0;
		pl->y0 = -1;
		pl->x0 = -1;
		pl->len = 10000000;
		pl->er1 = 0;
		pl->er2 = 0;
	}
	if (i == 1)
	{
		pl->y2 = -1000;
		pl->x2 = -1000;
		pl->g = -1;
	}
}
