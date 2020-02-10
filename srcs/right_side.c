/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_side.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:55:06 by bkuksa            #+#    #+#             */
/*   Updated: 2019/04/24 20:55:11 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_side_xy(t_map *map, t_player *pl)
{
	pl->i1 = (pl->tet1 - 1 >= 0) ? pl->tet1 - 1 : 0;
	while (pl->er == 0 && pl->i1 < map->size_map_y && pl->i1 <= pl->tet2 + 1)
	{
		pl->i2 = (pl->i2 == map->size_map_x) ? 0 : pl->i2 + 1;
		while ((pl->er = 0) == 0 && pl->er == 0 && pl->i2 < map->size_map_x)
		{
			pl->er = ft_error_x(map, pl, pl->i1, pl->i2);
			pl->er = ft_error_o(map, pl, pl->i1, pl->i2) + pl->er;
			pl->i2 = (pl->er == 0 || pl->er == 1) ? pl->i2 + 1 : pl->i2;
			if (pl->er == 2)
				break ;
		}
		if (pl->er == 2 && (ft_route1(map, pl) > 0))
		{
			pl->zenna = (pl->zenna == NULL) ? ft_itoa(pl->i1)
							: ft_strjoin_fix(ft_itoa(pl->i1), pl->zenna, 3);
			pl->zenna = ft_strjoin_fix(" ", pl->zenna, 2);
			pl->zenna = ft_strjoin_fix(ft_itoa(pl->i2), pl->zenna, 3);
			pl->zenna = ft_strjoin_fix(",", pl->zenna, 2);
		}
		pl->i1 = (pl->er == 0 || pl->er == 1) ? pl->i1 + 1 : pl->i1;
		pl->er = 0;
	}
}

int		ft_route1(t_map *map, t_player *pl)
{
	pl->v = 0;
	pl->z = -2;
	pl->kanon = ft_itoa(pl->i1);
	pl->kanon = ft_strjoin_fix(pl->kanon, " ", 1);
	pl->kanon = ft_strjoin_fix(pl->kanon, ft_itoa(pl->i2), 3);
	pl->kanon = ft_strjoin_fix(pl->kanon, ",", 1);
	ft_start(map, pl, pl->i1, pl->i2);
	free(pl->kanon);
	if (pl->v < 5)
		pl->v = 0;
	return (pl->v);
}

void	ft_chaos(t_map *map, t_player *pl, int i)
{
	while (i < (int)ft_strlen(pl->zenna))
	{
		pl->i2 = ft_atoi(&pl->zenna[i]);
		while (ft_isdigit(pl->zenna[i]) == 1)
			i++;
		i++;
		pl->i1 = ft_atoi(&pl->zenna[i]);
		while (ft_isdigit(pl->zenna[i]) == 1)
			i++;
		i++;
		if ((pl->h = 0) == 0 && (pl->i1 == pl->y0 && pl->i2 == pl->x0))
			pl->f = 0;
		pl->v = 0;
		pl->z = -2;
		pl->kanon = ft_itoa(pl->i1);
		pl->kanon = ft_strjoin_fix(pl->kanon, " ", 1);
		pl->kanon = ft_strjoin_fix(pl->kanon, ft_itoa(pl->i2), 3);
		pl->kanon = ft_strjoin_fix(pl->kanon, ",", 1);
		ft_start(map, pl, pl->i1, pl->i2);
		free(pl->kanon);
		if (((pl->f == -2 && pl->z >= 0)
							|| (pl->z < pl->f && pl->z >= 0)))
			pl->f = pl->z;
	}
}

void	ft_start(t_map *map, t_player *pl, int y, int x)
{
	int		y1;
	int		x1;

	y1 = (y - 1 < 0) ? y - 1 : y - 2;
	while (++y1 < map->size_map_y && y1 <= y + 1)
	{
		x1 = (x - 1 < 0) ? x - 1 : x - 2;
		while (++x1 < map->size_map_x && x1 <= x + 1)
		{
			if ((pl->bog == 'X' && ft_error_x(map, pl, y1, x1) > 0)
				|| (pl->bog == 'O' && ft_error_o(map, pl, y1, x1) > 0))
			{
				if (ft_if_start(map, pl, y1, x1) != 0 && y1 == pl->y0
					&& x1 == pl->x0 && (pl->z == -2 || pl->z > pl->v))
					pl->z = pl->v;
				if ((pl->z == 1 || pl->z == 0 || pl->v > 10 || pl->z > 7)
					|| (pl->h == 8 && pl->v > 5))
					break ;
			}
		}
		if ((pl->z == 1 || pl->z == 0 || pl->v > 10 || pl->z > 7)
			|| (pl->h == 8 && pl->v > 5))
			break ;
	}
	pl->v = (pl->h == 8) ? pl->v : pl->v + 1;
}

int		ft_if_start(t_map *map, t_player *pl, int y1, int x1)
{
	if ((ft_klon(pl->kanon, y1, x1)) > 0)
	{
		pl->kanon = ft_strjoin_fix(pl->kanon, ft_itoa(y1), 3);
		pl->kanon = ft_strjoin_fix(pl->kanon, " ", 1);
		pl->kanon = ft_strjoin_fix(pl->kanon, ft_itoa(x1), 3);
		pl->kanon = ft_strjoin_fix(pl->kanon, ",", 1);
		pl->v++;
		if (((y1 != pl->y0 || x1 != pl->x0) && pl->v < 10)
										|| (pl->h == 8 && pl->v < 5))
			ft_start(map, pl, y1, x1);
		return (1);
	}
	return (0);
}
