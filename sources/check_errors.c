/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:52:36 by jcharloi          #+#    #+#             */
/*   Updated: 2017/08/24 16:59:01 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_doubles(t_ps *ps, int o, long nb)
{
	int		i;

	i = 0;
	while (i < o)
	{
		if (ps->a[i] == nb)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		i++;
	}
}

static void		check_letters(char *str)
{
	int		j;

	j = 0;
	if (str[0] == '-' || str[0] == '+')
		j++;
	while (str[j] != '\0')
	{
		if (ft_isdigit(str[j]) != 1)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		j++;
	}
}

static int		next(t_ps *ps, char **tab, int o)
{
	long	nb;
	int		i;

	i = 0;
	while (tab[i] != '\0')
	{
		nb = ft_atol(tab[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		if (o > 0)
			check_doubles(ps, o, nb);
		ps->size_a++;
		if (!(ps->a = ft_taballoc(ps->a, ps->size_a * sizeof(int))))
			ft_error("Malloc errror");
		ps->a[o++] = nb;
		check_letters(tab[i]);
		i++;
	}
	return (o);
}

void			check_error(t_ps *ps, int argc, char **argv)
{
	char	**tab;
	int		t;
	int		o;

	t = 1;
	o = 0;
	if (argc < 2)
		exit(0);
	while (t < argc)
	{
		tab = ft_strsplit(argv[t], ' ');
		o = next(ps, tab, o);
		t++;
		ft_tabdel(&tab);
	}
}
