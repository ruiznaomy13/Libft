/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:26:28 by ncastell          #+#    #+#             */
/*   Updated: 2022/11/30 22:21:54 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s1;

	i = -1;
	if (!s || !f)
		return (NULL);
	s1 = (char *)(malloc(sizeof(char) * (ft_strlen((char *)s) + 1)));
	if (!s1)
		return (NULL);
	while (s[++i])
		s1[i] = f(i, s[i]);
	s1[i] = '\0';
	return (s1);
}
