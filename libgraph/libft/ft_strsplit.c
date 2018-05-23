/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:00:24 by bspindle          #+#    #+#             */
/*   Updated: 2017/11/18 13:54:12 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_create_table(char const *s, char c)
{
	char	**tab;
	int		t[3];

	if (!(tab = (char**)malloc(sizeof(char*) * (ft_strlen(s) + 1))))
		return (NULL);
	t[1] = 0;
	t[0] = 0;
	while (s[t[1]] != '\0')
	{
		t[2] = 0;
		while (s[t[1]] == c && s[t[1]] != '\0')
			t[1]++;
		while (s[t[1]] != c && s[t[1]] != '\0')
		{
			t[1]++;
			t[2]++;
		}
		if (!(tab[t[0]] = malloc(sizeof(char) * (t[2] + 1))))
			return (NULL);
		tab[t[0]][t[2]] = '\0';
		t[0]++;
	}
	tab[t[0]] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		t[3];

	if (s == NULL || !(tab = ft_create_table(s, c)))
		return (NULL);
	t[1] = 0;
	t[0] = 0;
	while (s[t[1]] != '\0')
	{
		t[2] = 0;
		while (s[t[1]] == c && s[t[1]] != '\0')
			t[1]++;
		while (s[t[1]] != c && s[t[1]] != '\0')
		{
			tab[t[0]][t[2]] = s[t[1]];
			t[1]++;
			t[2]++;
		}
		if (t[2] == 0)
			tab[t[0]] = NULL;
		t[0]++;
	}
	return (tab);
}
