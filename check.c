/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:05:59 by dferjul           #+#    #+#             */
/*   Updated: 2023/06/08 01:54:48 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_check_only_numbers(char **av, int ac)
{
	int	i;

	i = 0;
	while (av[ac])
	{
		if (av[ac][i] == 45 || av[ac][i] == 43)
			i++;
		while (av[ac][i])
		{
			if (av[ac][i] <= 47 || av[ac][i] >= 59)
				ft_error();
			i++;
		}
		i = 0;
		ac++;
	}
}

void	ft_check_sorted_list(t_list *groot)
{
	t_element	*tmp;
	t_element	*new;

	tmp = groot->a;
	new = groot->a->next;
	while (new)
	{
		if (new->value > tmp->value)
		{
			new = new->next;
			tmp = tmp->next;
			if (new == NULL)
				exit(EXIT_SUCCESS);
		}
		else
			break ;
	}
}

void	ft_check_overflow(char **av, int ac)
{
	int	i;
	int	size;

	while (av[ac])
	{
		i = 0;
		while (av[ac][i] == '+' || av[ac][i] == '-' || av[ac][i] == '0')
			i++;
		size = ft_strlen(av[ac] + i);
		if (size == 10)
		{
			if (av[ac][0] == '-')
			{
				if (ft_strcmp(&(av[ac][i]), "2147483648") > 0)
					ft_error();
			}
			else
				if (ft_strcmp(&(av[ac][i]), "2147483647") > 0)
					ft_error();
		}
		else if (size > 10)
			ft_error();
		ac++;
	}
}

void	ft_check_double(t_list *groot)
{
	t_element	*tmp;
	t_element	*new;
	int			i;

	tmp = groot->a;
	new = groot->a;
	i = 0;
	while (new)
	{
		while (tmp != NULL)
		{
			if (new->value == tmp->value)
			{
				i++;
				if (i > 1)
					ft_error();
				tmp = tmp->next;
			}
			else
				tmp = tmp->next;
		}
		i = 0;
		tmp = groot->a;
		new = new->next;
	}
}
