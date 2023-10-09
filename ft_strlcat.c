/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:03:24 by ncastell          #+#    #+#             */
/*   Updated: 2022/10/09 18:23:44 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	len = ft_strlen(dst) + ft_strlen(src);
	if (dstsize <= d)
		return ((len - d) + dstsize);
	i = 0;
	while ((i < dstsize - (len - s) - 1) && src[i])
	{
		dst[d] = src[i];
		i++;
		d++;
	}
	dst[d] = '\0';
	return (len);
}
