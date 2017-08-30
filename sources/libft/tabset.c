/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 15:21:16 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/07 15:21:35 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tabset(int *tab, int c, int len)
{
	int		i;

	i = 0;
	while (len)
	{
		tab[i] = c;
		len--;
		i++;
	}
}