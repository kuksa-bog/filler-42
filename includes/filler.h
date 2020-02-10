/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:56:03 by bkuksa            #+#    #+#             */
/*   Updated: 2019/05/13 11:32:36 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# define FD 0

typedef struct	s_map
{
	int			size_map_y;
	int			size_map_x;
	int			size_tet_y;
	int			size_tet_x;
	char		**map;
	char		**tet;
	int			i;
	char		*line;
	int			fd;
	int			x;
	int			y;
}				t_map;

typedef struct	s_player
{
	char		bog;
	char		dev;
	int			i;
	int			xp;
	int			yp;
	int			n;
	int			x;
	int			y;
	int			error;
	int			xt;
	int			yt;
	int			yl;
	int			xl;
	int			xu;
	int			yu;
	double		k;
	int			j1;
	int			j2;
	int			i1;
	int			i2;
	int			er;
	int			y0;
	int			x0;
	int			y2;
	int			x2;
	double		len;
	int			er1;
	int			er2;
	int			v;
	int			f;
	int			z;
	int			g;
	char		*kanon;
	int			tet1;
	int			tet2;
	int			a1;
	int			a2;
	int			a3;
	int			a4;
	int			a5;
	int			z1;
	char		*zenna;
	int			h;
	double		k1;
}				t_player;

void			ft_initialization1(t_map *map, t_player *pl);
void			ft_initialization2(t_player *pl);
void			ft_initialization3(t_map *map, t_player *pl);
void			ft_initial_alg(t_player *pl, int i);

void			ft_cut(t_map *map, t_player *pl);
void			ft_cut2(t_map *map, t_player *pl);
void			ft_free2(t_map *map, char **s, t_player *pl);
void			ft_boundar(t_map *map, t_player *pl);
void			ft_start_alg(t_player *pl, t_map *map);

void			ft_size_map(t_map *map);
void			ft_size_tet(t_map *map);
void			ft_read_map(t_map *map);
void			ft_read_tet(t_map *map);
char			*ft_strjoin_fix(char *s1, char *s2, int n);

void			ft_player(t_player *pl, t_map *map);
void			ft_tet_place(t_map *map, t_player *pl);
void			ft_route4(t_map *map, t_player *pl);
void			ft_route5(t_map *map, t_player *pl);
void			ft_start_route(t_map *map, t_player *pl);

void			ft_search_x0(t_player *pl, t_map *map);
void			ft_cycle(t_player *pl, t_map *map);
void			ft_valid_place(t_player *pl, t_map *map);
void			ft_valid_place2(t_player *pl, t_map *map);
void			ft_new_distance(t_player *pl, t_map *map);

double			ft_distance(int y1, int x1, int y2, int x2);
int				ft_pow(int n, int p);
double			ft_sqrt_dub(double x);
void			ft_free(t_map *map);
void			ft_write(t_player *pl);

void			ft_alg2(t_player *pl, t_map *map);
void			ft_alg2_1(t_player *pl, t_map *map);
int				ft_error_x(t_map *map, t_player *pl, int i1, int i2);
int				ft_error_o(t_map *map, t_player *pl, int i1, int i2);
int				ft_klon(char *kanon, int y, int x);

void			ft_side_xy(t_map *map, t_player *pl);
void			ft_chaos(t_map *map, t_player *pl, int i);
void			ft_start(t_map *map, t_player *pl, int y, int x);
int				ft_if_start(t_map *map, t_player *pl, int y1, int x1);
int				ft_route1(t_map *map, t_player *pl);

#endif
