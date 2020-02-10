/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_folow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:43:10 by bkuksa            #+#    #+#             */
/*   Updated: 2019/04/22 12:46:17 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_search_x0(t_player *pl, t_map *map)
{
	ft_initial_alg(pl, 1);
	if (pl->z1 == -1)
		ft_start_route(map, pl);
	if (pl->z1 != 6)
		ft_side_xy(map, pl);
	map->i = pl->tet1;
	while (map->map[map->i] && map->i < map->size_map_y && map->i <= pl->tet2)
	{
		pl->i = 0;
		while (map->map[map->i][pl->i])
			ft_cycle(pl, map);
		map->i++;
	}
	pl->z1 = (pl->z1 == 6) ? -1 : pl->z1;
}

void	ft_cycle(t_player *pl, t_map *map)
{
	if ((map->map[map->i][pl->i] == 'X' && pl->bog == 'O')
		|| (map->map[map->i][pl->i] == 'O' && pl->bog == 'X')
		|| map->map[map->i][pl->i] == '.')
		pl->i++;
	else if (map->map[map->i][pl->i])
	{
		pl->xt = 0;
		pl->yt = 0;
		while (pl->yt < map->size_tet_y && map->tet[pl->yt][pl->xt])
		{
			pl->yu = -1;
			pl->xu = -1;
			ft_valid_place(pl, map);
			pl->yt = (pl->xt == map->size_tet_x - 1) ? pl->yt + 1 : pl->yt;
			pl->xt = (pl->xt < map->size_tet_x - 1) ? pl->xt + 1 : 0;
		}
		pl->i++;
	}
}

void	ft_valid_place(t_player *pl, t_map *map)
{
	pl->j1 = 0;
	pl->error = 0;
	pl->i1 = map->i - pl->yt;
	while (pl->error == 0 && pl->j1 < map->size_tet_y && map->tet[pl->j1])
	{
		pl->j2 = 0;
		pl->i2 = pl->i - pl->xt;
		while (pl->error == 0 && map->tet[pl->j1][pl->j2])
			ft_valid_place2(pl, map);
		pl->i1++;
		pl->j1++;
	}
	if (pl->yu == -1 || pl->xu == -1)
		pl->error = 1;
	ft_new_distance(pl, map);
}

void	ft_valid_place2(t_player *pl, t_map *map)
{
	if (((pl->i1 >= 0 && pl->i1 < map->size_map_y)
		&& (pl->i2 >= 0 && pl->i2 < map->size_map_x)) &&
		pl->yu == -1 && map->map[pl->i1][pl->i2] == pl->bog
		&& map->tet[pl->j1][pl->j2] == '*' && ((pl->yu = pl->i1) || !pl->i1))
		pl->xu = pl->i2;
	if ((((pl->i1 >= 0 && pl->i1 < map->size_map_y)
			&& (pl->i2 >= 0 && pl->i2 < map->size_map_x))
			&& ((pl->bog == map->map[pl->i1][pl->i2]
			&& map->tet[pl->j1][pl->j2] == '*'
			&& (pl->xu != pl->i2 || pl->yu != pl->i1))
			|| (pl->dev == map->map[pl->i1][pl->i2]
			&& map->tet[pl->j1][pl->j2] == '*')))
			|| (!((pl->i1 >= 0 && pl->i1 < map->size_map_y)
			&& (pl->i2 >= 0 && pl->i2 < map->size_map_x))
			&& map->tet[pl->j1][pl->j2] == '*'))
		pl->error = 1;
	if (pl->error == 0 && pl->j1 == pl->yp
		&& pl->j2 == pl->xp && (pl->yl = pl->i1))
		pl->xl = pl->i2;
	pl->i2++;
	pl->j2++;
}

void	ft_new_distance(t_player *pl, t_map *map)
{
	if (pl->z1 != 6 && pl->error == 0 && pl->zenna != NULL)
		ft_alg2(pl, map);
	pl->i1 = -1;
	while (pl->z1 != 6 && pl->error == 0 && (pl->i1 = pl->i1 + 5)
		< map->size_map_y && pl->y2 == -1000 && pl->x2 == -1000)
	{
		pl->j1 = -1;
		while (++pl->j1 < map->size_map_x)
		{
			if (pl->error == 0 && ((map->map[pl->i1][pl->j1] == 'X'
					&& pl->bog == 'O') || (map->map[pl->i1][pl->j1] == 'O'
												&& pl->bog == 'X')))
			{
				if (ft_distance(pl->i1, pl->j1, pl->yl, pl->xl) < pl->k)
				{
					pl->k = ft_distance(pl->i1, pl->j1, pl->yl, pl->xl);
					pl->x = pl->i - pl->xt - map->x;
					pl->y = map->i - pl->yt - map->y;
				}
				break ;
			}
		}
	}
	if (pl->error == 0 && pl->z1 == 6)
		ft_start_alg(pl, map);
}
