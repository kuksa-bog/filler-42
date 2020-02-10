/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:40:32 by bkuksa            #+#    #+#             */
/*   Updated: 2019/04/25 17:40:34 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_free(t_map *map)
{
	map->i = 0;
	while (map->i < map->size_map_y)
	{
		free(map->map[map->i]);
		map->i++;
	}
	map->i = 0;
	while (map->i < map->size_tet_y)
	{
		free(map->tet[map->i]);
		map->i++;
	}
}

double	ft_sqrt_dub(double x)
{
	long	i;

	i = 1;
	if (x < 0)
		return (0);
	while (i * i < x)
		i += 1;
	return (i);
}

double	ft_distance(int y1, int x1, int y2, int x2)
{
	int		a;
	int		b;
	double	c;

	a = ((y1 - y2) > 0) ? (y1 - y2) : (y2 - y1);
	b = ((x1 - x2) > 0) ? (x1 - x2) : (x2 - x1);
	c = ft_sqrt_dub((double)(ft_pow(a, 2) * 100 + ft_pow(b, 2) * 100));
	return (c);
}

int		ft_pow(int n, int p)
{
	int		result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

void	ft_write(t_player *pl)
{
	if (pl->y2 == -1000 && pl->x2 == -1000 && pl->x == -1000 && pl->y == -1000)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
	}
	else if (pl->y2 == -1000 || pl->x2 == -1000)
	{
		ft_putnbr(pl->y);
		ft_putchar(' ');
		ft_putnbr(pl->x);
		ft_putchar('\n');
	}
	else if (pl->y2 != -1000 && pl->x2 != -1000)
	{
		ft_putnbr(pl->y2);
		ft_putchar(' ');
		ft_putnbr(pl->x2);
		ft_putchar('\n');
	}
}
