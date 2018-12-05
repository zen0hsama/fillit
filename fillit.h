/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:39:40 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/05 17:16:09 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"

int		ft_checkall(char *tab);
int		ft_check_line(char *line);
int		ft_usage(void);
char	**ft_algo(char **tetrimino, int i, int nb_tetri);


#endif
