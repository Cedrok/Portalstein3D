/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:43:12 by cvautrai          #+#    #+#             */
/*   Updated: 2018/04/11 09:18:36 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	Open and read file in order to count the number of lines and the biggest
**	line
*/

static int	get_mlen(char *arg, char *line, int *nblines)
{
	int		fd;
	size_t	mlen;
	int		gnl;

	if ((fd = open(arg, O_RDONLY)) == -1)
		return (-1);
	mlen = 0;
	gnl = 1;
	while (gnl)
	{
		if ((gnl = get_next_line(fd, &line)) == -1)
			return (-1);
		if (ft_strlen(line) > mlen)
			mlen = ft_strlen(line);
		ft_strdel(&line);
		*nblines += 1;
	}
	close(fd);
	if (!mlen)
		return (-1);
	return (mlen);
}

/*
**	Fill a str with '0's and terminate it with a '\0'
*/

static char	*full_zero(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	ft_putendl(str);
	return (str);
}

/*
**	Fill a str with given line. If needed, end the str with '0's
*/

static char	*fill_line(char *str, char *line, size_t len)
{
	size_t	i;
	int		j;

	str[0] = '0';
	i = 1;
	j = 0;
	while (i <= ft_strlen(line))
	{
		if (line[j] != '0')
			str[i] = '1';
		else
			str[i] = line[j];
		i++;
		j++;
	}
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	ft_putendl(str);
	return (str);
}

/*
**	Fill the map with given file
*/

static char	**fill_map(char **map, char *arg, size_t mlen, int nb_lines)
{
	int		i;
	int		fd;
	char	*line;
	int		gnl;

	line = NULL;
	if ((fd = open(arg, O_RDONLY)) == -1)
		return (NULL);
	map[0] = full_zero(map[0], mlen + 2);
	i = 1;
	while (i <= nb_lines)
	{
		if ((gnl = get_next_line(fd, &line)) == -1)
			return (NULL);
		map[i] = fill_line(map[i], line, mlen + 2);
		i++;
		ft_strdel(&line);
	}
	map[i] = full_zero(map[i], mlen + 2);
	close(fd);
	return (map);
}

/*
**	Malloc and fill a map
*/

char		**get_map(char *arg, char *line, t_wolf3d_data *wolf)
{
	int		i;
	size_t	mlen;
	int		nb_lines;
	char	**map;

	nb_lines = -1;
	if ((mlen = get_mlen(arg, line, &nb_lines)) == -1)
		return (NULL);
	if (!(map = (char**)malloc(sizeof(char*) * (nb_lines + 3))))
		return (NULL);
	i = 0;
	while (i < nb_lines + 2)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (mlen + 3))))
			return (NULL);
		i++;
	}
	map[i] = NULL;
	ft_putendl("[] Map :");
	map = fill_map(map, arg, mlen, nb_lines);
	wolf->map_w = mlen + 2;
	wolf->map_h = nb_lines + 2;
	return (map);
}
