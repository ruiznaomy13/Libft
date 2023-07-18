/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:55:02 by ncastell          #+#    #+#             */
/*   Updated: 2022/12/23 17:01:16 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	num;
	int				neg;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = ((num * 10) + (str[i] - '0'));
		i++;
	}
	return ((int)(num * neg));
}
/*
int	main(){
	char num[10] = " -477";
	//char num1[10] = " 122";

	printf("La cadena \"%s\" = numero: %d\n", num, atoi(num));
	printf("La cadena \"%s\" = numero: %d\n", num, ft_atoi(num));
}*/
