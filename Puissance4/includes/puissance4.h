/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:33:04 by abary             #+#    #+#             */
/*   Updated: 2016/02/28 23:40:34 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H
# define WINNER 0
# define PLAYER 1
# define PIECE 2
# define VALMAX 0
# define VALMIN 1
# define COLMAX 2
# define COLMIN 3
# define RETMIN 4
# define RETMAX 5

/*
********************************************************************************
**								TAILLES
********************************************************************************
*/
int g_line;
int	g_col;
/*
*******************************************************************************
**								GAME										  *
*******************************************************************************
*/
int		ft_puissance4(char **puissance4);
int		ft_check_winner(char **puissance4, int size, int player);
/*
*******************************************************************************
**								AI   										  *
*******************************************************************************
*/
int		ft_ia(char **puissance4, int piece);
int		ft_getval(int *tab);
int		ft_win_loose(char **puissance4, int piece);
void	ft_calcul_ia(char **p4, int piece, int *tab, int pro);
void	ft_calcul_player(char **p4, int piece, int *tab, int pro);
void	ft_destruct_tab(int *tab);
void	ft_val_max_min(int *tab, int i);
/*
*******************************************************************************
**								Error management							  *
*******************************************************************************
*/
int		ft_check_args(char **args);
void	ft_display_error(int error);
int		ft_check_value(char *str);
void	ft_display_wrong_input(int error);

/*
*******************************************************************************
**								create game									  *
*******************************************************************************
*/
char	**ft_init_board(char **argv);
int		ft_select_player(void);
int		ft_pos_piece(char **puissance4, int input, int piece);
void	ft_ret_piece(char **p4, int col, int piece);
char	**ft_create_board(char **p4);
void	ft_menu(char **puissance);
void	ft_destruct_board(char **board);
/*
*******************************************************************************
**								dispaly Board								  *
*******************************************************************************
*/
void	ft_display_board(char **board);
void	ft_display_menu(void);
void	ft_display_you_won(void);
void	ft_display_you_loose(void);
void	ft_display_null(void);
void	ft_display_line(int line);
void	ft_display_victory(char **board, int plqyer, int winner);
/*
*******************************************************************************
**								Input user									  *
*******************************************************************************
*/
int		ft_recup_input(char **p4);
void	ft_free_line(char *line);
/*
******************************************************************************
**								Check										  *
*******************************************************************************
*/
int		ft_check_column(char **tab, int col);
void	ft_uncheck_column(int *tabcol, int col);
int		ft_check_wline(char **puissance4, int player);
int		ft_check_wcol(char **puissance4, int player);
int		ft_check_wdiag(char **puissance4, int player);
int		ft_check_diag_droite(char **tab, int i, int j);
int		ft_check_diag_gauche(char **tab, int i, int j);
int		ft_check_diag_vd_droite(char **tab, int i, int j);
int		ft_check_diag_vd_gauche(char **tab, int i, int j);
int		ft_check_line_vd(char **tab, int i, int j, char p);
int		ft_check_col_vd(char **tab, int i, int j, char p);
int		ft_check_col_vd(char **tab, int i, int j, char p);
int		ft_check_max(char **p4, int piece, int col, int ligne);
#endif
