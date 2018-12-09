/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:47:46 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/07 10:18:55 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void			ft_form_tetrimino(char **tetrimino)
{
	static char		letter;
	int				i;
	static int		j;
	static int		k;

	i = 0;
	if (!k)
		k = 5;
	if (!letter)
		letter = 'A';
	while (j < k)
	{
		while (tetrimino[j][i])
		{
			if (tetrimino[j][i] == '#')
				tetrimino[j][i] = letter;
			i++;
		}
		j++;
		i = 0;
	}
	tetrimino[j] = NULL;
	k = k + 5;
	letter++;
	ft_algo(tetrimino, 0, 0);
}

static int		ft_stock_tetrimino(char *stock[5], int nb_tetri)
{
	static char		**tetrimino;
	static int		i;
	static int		j;
	int				k;

	k = 0;
	if (!i)
		i = 5;
	if (!tetrimino)
		if (!(tetrimino = (char**)malloc(sizeof(char*) * nb_tetri * 5 + 1)))
			return (-1);
	while (j < i)
	{
		if (!(tetrimino[j] = ft_strdup(stock[k])))
			return (-1);
		j++;
		k++;
	}
	ft_form_tetrimino(tetrimino);
	i = i + 5;
	return (0);
}

static int		ft_stock(char *line, int nb_tetri)
{
	static char		*stock[5];
	char			*tetra;
	static int		i;

	tetra = "";
	if (!(stock[i] = ft_strdup(line)))
		return (-1);
	i++;
	if (i == 4)
	{
		i = 0;
		while (i < 4)
		{
			if (!(tetra = ft_strjoin(tetra, stock[i])))
				return (-1);
			if (!(tetra = ft_strjoin(tetra, " ")))
				return (-1);
			i++;
		}
		stock[i] = "\0";
		if ((i = ft_checkall(tetra)) == -1)
			return (-1);
		if ((i = ft_stock_tetrimino(stock, nb_tetri)) == -1)
			return (-1);
	}
	return (i);
}

static int			ft_norminette(char *line, int fd, int ret, int nb_tetri)
{
	ret = ft_stock(line, nb_tetri);
	if (ret == -1)
		return (0);
	if (ret == 0 && (get_next_line(fd, &line) == -1))
		return (0);
	if (ret == 0 && ft_check_line(line) == -1)
		return (0);
	return (1);
}

int		main(int ac, const char **av)
{
	char	*line;
	int		fd;
	int		ret = 0;
	int		nb_tetri;

	nb_tetri = 1;
	if (ac != 2)
		return (ft_usage());
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		if (!ft_strlen(line))
			nb_tetri++;
	close(fd);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		if (ft_norminette(line, fd, ret, nb_tetri) == 0)
			return (0);
	if (!(ft_algo(NULL, 1, nb_tetri)))
		return (0);
	return (0);
}
