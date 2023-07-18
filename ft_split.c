/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:20:25 by ncastell          #+#    #+#             */
/*   Updated: 2022/12/31 12:41:13 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>*/
#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	ft_wlen(char const *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_free(char **str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		free(str[a]);
		a++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!str)
		return (NULL);
	while (j < ft_countwords(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = (ft_substr(s, i, ft_wlen(s, i, c)));
		if (!str[j])
			return (ft_free(str));
		i += ft_wlen(s, i, c);
		j++;
	}
	str[j] = 0;
	return (str);
}
/*
int	main(void)
{
	char **resul = ft_split("Hola, soy, Naomy Cast, y, me gusta, comer, pan.", ',');
	int	i = 0;

	while (resul[i])
	{
		printf("%s  ", resul[i]);
		i++;
	}
	printf("%d", ft_countwords("Hola, me, llamo, nao, y, tengo, 21.", ','));

}*/
