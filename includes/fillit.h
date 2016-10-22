/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:16:26 by hdecaux           #+#    #+#             */
/*   Updated: 2016/10/22 01:40:50 by rthys            ###   ########.fr       */
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
# define LET tetri->let
# define X_FIRST cd->x_first
# define Y_FIRST cd->y_first
# define NEWYM Y_M + Y_P
# define NEWXM X_M + X_P
# define SAVE cd->savemap
# define RANK tetri->rank
# define TETRI tetri->tetri
# define PREV tetri->previous
# define NEXT tetri->next
# define LEN tetri->len
# define STOCK cd->stock
# define BEGIN cd->begin_list
# define ASTOCK cd->a_stock
# define BCOTE cd->b_cote
# define BMAP cd->b_map
# define PLACED cd->placed
# define LAR tetri->larg

typedef struct		s_int
{
	int				i;
	int				j;
	int				k;
}					t_int;

typedef	struct		s_etri
{
	size_t			rank;
	char			**tetri;
	char			let;
	int				len;
	int				larg;
	struct s_etri	*previous;
	struct s_etri	*next;
}					t_etri;

typedef struct	s_coord
{
	size_t			*stock;
	int				x_m;
	int				y_m;
	int				x_p;
	int				y_p;
	size_t			nb_p;
	int				cote;
	int				b_cote;
	size_t			nb_l;
	int				x_first;
	int				y_first;
	size_t			a_stock;
	size_t			placed;
	char			*buf;
	char			**tab;
	char			**map;
	char			**savemap;
	char			**b_map;
	struct s_etri	*begin_list;
}					t_coord;

/* ft_errors.c */

int					ft_errors(int ret, char *buf, char **tab);
int					ft_dot(char *buf);
int					ft_chrn(char *buf);
int					ft_col(char *buf);
int					ft_diese(char **tab, char *buf);

/* ft_bufcpy.c */

char				**ft_bufcpy(char *buf, t_coord *cd);
int					ft_countl(char *buf);
void				ft_putstr(char const *str);
void				ft_puttab(char **tab, char *buf);
char				**ft_malloc_tab(char **tab, char *buf);

/* ft_check_valid.c */

int					ft_valid(char **tab, char *buf);
int					ft_check_first(char **tab, int i);
int					ft_check_last(char **tab, int i);
int					ft_check_lines(char **tab, int i);

/* ft_pieces_l.c */

char				*ft_is_lhorl(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_lhorr(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_lverr(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_lverl(char **tab, char *buf, int *pieces, int *found);

/* ft_pieces_revlsq.c */

char				*ft_is_square(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_lrevhorl(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_lrevhorr(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_lrevverr(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_lrevverl(char **tab, char *buf, int *pieces, int *found);

/* ft_line_s_z.c */

char				*ft_is_line_hor(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_line_ver(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_s(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_s_up(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_z(char **tab, char *buf, int *pieces, int *found);

/* ft_z_t.c */

char				*ft_is_z_up(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_t(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_t_left(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_t_right(char **tab, char *buf, int *pieces, int *found);
char				*ft_is_t_up(char **tab, char *buf, int *pieces, int *found);

/* ft_trim.c */

char				*ft_trim(char **tab, char *buf, int *pieces, int *found);
char				*ft_sub_trim(char **tab, char *buf);
void				ft_count_pieces(t_coord *cd);
char				**ft_cpy_tab(char **tab2, t_coord *cd);

/* ft_parser.c */

char				*ft_test_l(char **tab, char *buf, int *pieces, int *found);
char				*ft_test_t(char **tab, char *buf, int *pieces, int *found);
int					ft_hash(char *str, size_t n);
int					ft_dota(char *str, size_t n);

/* ft_resolve.c */

char				**ft_map_creator(size_t cotes);
int					ft_check_tetri(t_coord *cd, t_etri *tetri, t_int *pmap);
void				ft_place_tetri(t_coord *cd, t_etri *tetri, char c, t_int *pmap);
void				ft_prepare_algo(t_coord *cd, t_etri *tetri);
int					ft_resolve(t_coord *cd, t_etri *tetri);
int					ft_sqrt(int nbr);

/* ft_create_list.c */

t_etri				*ft_add_list(t_coord *cd, t_etri *tetri, size_t i, size_t *j);
t_etri				*ft_make_list(t_coord *cd);
char				*ft_cpy_tetri(t_coord *cd, size_t *j);
void				ft_cpy_first(t_coord *cd, t_etri *tetri, size_t *j);

#endif
