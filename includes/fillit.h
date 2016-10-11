/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:16:26 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/11 21:37:00 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define BUFF_SIZE 1000
# define X_M cd->x_m
# define Y_M cd->y_m
# define X_P cd->x_p
# define Y_P cd->y_p
# define NB_P cd->nb_p
# define NB_L cd->nb_l
# define MAP cd->map
# define TAB cd->tab
# define TABP TAB[Y_P][X_P]
# define COTE cd->cote
# define BUF cd->buf
# define TABCT tab[ct.i][ct.j]
# define LET cd->letter
# define X_FIRST cd->x_first
# define Y_FIRST cd->y_first
# define NEWYM Y_M + (Y_P - Y_FIRST)
# define NEWXM X_M + (X_P - X_FIRST)
# define SAVE cd->savemap

typedef struct	s_int
{
	int i;
	int j;
	int k;
}				t_int;

typedef struct	s_coord
{
	size_t	x_m;
	size_t	y_m;
	size_t	x_p;
	size_t	y_p;
	size_t	nb_p;
	size_t	cote;
	size_t	nb_l;
	size_t	x_first;
	size_t	y_first;
	char	*buf;
	char	**tab;
	char	**map;
	char	**savemap;
	char	letter;
}				t_coord;

/* ft_errors.c */

int				ft_errors(int ret, char *buf, char **tab);
int				ft_dot(char *buf);
int				ft_chrn(char *buf);
int				ft_col(char *buf);
int				ft_diese(char **tab, char *buf);

/* ft_bufcpy.c */

char			**ft_bufcpy(char *buf, t_coord *cd);
int				ft_countl(char *buf);
void			ft_putstr(char const *str);
void			ft_puttab(char **tab, char *buf);
char			**ft_malloc_tab(char **tab, char *buf);

/* ft_check_valid.c */

int				ft_valid(char **tab, char *buf);
int				ft_check_first(char **tab, int i);
int				ft_check_last(char **tab, int i);
int				ft_check_lines(char **tab, int i);

/* ft_pieces_l.c */

char			*ft_is_lhorl(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_lhorr(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_lverr(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_lverl(char **tab, char *buf, int *pieces, int *found);

/* ft_pieces_revlsq.c */

char			*ft_is_square(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_lrevhorl(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_lrevhorr(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_lrevverr(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_lrevverl(char **tab, char *buf, int *pieces, int *found);

/* ft_line_s_z.c */

char			*ft_is_line_hor(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_line_ver(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_s(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_s_up(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_z(char **tab, char *buf, int *pieces, int *found);

/* ft_z_t.c */

char			*ft_is_z_up(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_t(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_t_left(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_t_right(char **tab, char *buf, int *pieces, int *found);
char			*ft_is_t_up(char **tab, char *buf, int *pieces, int *found);

/* ft_trim.c */

char			*ft_trim(char **tab, char *buf, int *pieces, int *found);
char			*ft_sub_trim(char **tab, char *buf);
void			ft_count_pieces(t_coord *cd);
char			**ft_cpy_tab(char **tab2, t_coord *cd);

/* ft_parser.c */

char			*ft_test_l(char **tab, char *buf, int *pieces, int *found);
char			*ft_test_t(char **tab, char *buf, int *pieces, int *found);
int			ft_hash(char *str, size_t n);
int			ft_dota(char *str, size_t n);

/* ft_map_creator.c */

char			**ft_map_creator(size_t cotes);
void			ft_place_tetri(t_coord *cd);
void			ft_prepare_algo(t_coord *cd);
void			ft_resolve(t_coord *cd);

#endif
