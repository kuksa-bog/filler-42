/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:33:58 by bkuksa            #+#    #+#             */
/*   Updated: 2019/04/22 12:47:34 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_player(t_player *pl, t_map *map)
{
	get_next_line(map->fd, &map->line);
	pl->bog = (char)((map->line[10] == '1') ? 'O' : 'X');
	pl->dev = (char)((map->line[10] == '1') ? 'X' : 'O');
	ft_strdel(&map->line);
}

void	ft_tet_place(t_map *map, t_player *pl)
{
	map->i = 0;
	pl->n = 0;
	while (map->i < map->size_tet_y)
	{
		pl->i = 0;
		while (pl->i < map->size_tet_x)
		{
			if (map->tet[map->i][pl->i] == '*')
				pl->n++;
			pl->i++;
		}
		map->i++;
	}
	ft_route4(map, pl);
	ft_route5(map, pl);
}

void	ft_route4(t_map *map, t_player *pl)
{
	pl->n = ((pl->n % 2) >= 1) ? pl->n + 1 : pl->n;
	pl->n = ((pl->n / 2) >= 1) ? (pl->n / 2) : 1;
	map->i = 0;
	while (map->i < map->size_tet_y && pl->n >= 0)
	{
		pl->i = 0;
		while (pl->i < map->size_tet_x)
		{
			if (map->tet[map->i][pl->i] == '*')
				pl->n--;
			pl->i++;
		}
		if (pl->n > 0)
			map->i++;
	}
	pl->yp = map->i;
}

void	ft_route5(t_map *map, t_player *pl)
{
	pl->i = 0;
	pl->n = 0;
	while (pl->i < map->size_tet_x)
	{
		if (map->tet[map->i][pl->i] == '*')
			pl->n++;
		pl->i++;
	}
	pl->i = 0;
	pl->n = ((pl->n % 2) > 0) ? (pl->n / 2) + 1 : (pl->n / 2);
	while (pl->i < map->size_tet_x && pl->n)
	{
		if (map->tet[map->i][pl->i] == '*')
			pl->n--;
		if (pl->n > 0)
			pl->i++;
	}
	pl->xp = pl->i;
}

void	ft_start_route(t_map *map, t_player *p)
{
	map->i = -1;
	while (p->z1 != 8 && p->z1 != 6 && ++map->i < map->size_map_y)
	{
		p->i = -1;
		while (p->z1 != 8 && ++p->i < map->size_map_x)
		{
			if (map->i < map->size_map_y / 2 && p->i < map->size_map_x / 2)
				p->a1 = (map->map[map->i][p->i] != '.') ? p->a1 + 1 : p->a1;
			if (map->i < map->size_map_y / 2 && p->i > map->size_map_x / 2)
				p->a2 = (map->map[map->i][p->i] != '.') ? p->a2 + 1 : p->a2;
			if (map->i > map->size_map_y / 2 && p->i < map->size_map_x / 2)
				p->a3 = (map->map[map->i][p->i] != '.') ? p->a3 + 1 : p->a3;
			if (map->i > map->size_map_y / 2 && p->i > map->size_map_x / 2)
				p->a4 = (map->map[map->i][p->i] != '.') ? p->a4 + 1 : p->a4;
			if (p->z1 != 8 && map->map[map->i][p->i] == p->bog
				&& ((p->bog == 'O' && ft_error_x(map, p, map->i, p->i) > 0)
				|| (p->bog == 'X' && ft_error_o(map, p, map->i, p->i) > 0)))
				p->z1 = 8;
		}
	}
	p->a5 = (p->a1 <= p->a2 && p->a1 <= p->a3 && p->a1 <= p->a4) ? -1 : p->a5;
	p->a5 = (p->a2 <= p->a1 && p->a2 <= p->a3 && p->a2 <= p->a4) ? -2 : p->a5;
	p->a5 = (p->a3 <= p->a2 && p->a3 <= p->a1 && p->a3 <= p->a4) ? -3 : p->a5;
	p->a5 = (p->a4 <= p->a2 && p->a4 <= p->a1 && p->a4 <= p->a3) ? -4 : p->a5;
	p->z1 = (p->z1 != 8) ? 6 : p->z1;
}
