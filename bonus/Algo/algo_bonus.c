/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <dferjul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:32:01 by dferjul           #+#    #+#             */
/*   Updated: 2023/06/08 15:54:26 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/checker.h"

void	ft_short_algo(t_list *groot)
{
	t_element	*big_value;

	big_value = ft_index_big_value(groot);
	if (big_value->index == groot->a->index)
	{
		ra(groot);
		if (groot->a->index > groot->a->next->index)
			sa(groot);
	}
	else if (big_value->index == groot->a->next->index)
	{
		rra(groot);
		if (groot->a->index > groot->a->next->index)
			sa(groot);
	}
	else if (big_value->index == groot->a->next->index)
	{
		if (groot->a->index > groot->a->next->index)
		{
			sa(groot);
		}
	}
}

void	ft_short_algo2(t_list *groot)
{
	t_element	*big_value;
	int			pos;
	int			i;

	big_value = ft_index_big_value(groot);
	while (groot->a->next)
	{
		if (big_value->index == groot->a->index)
			ra(groot);
		pb(groot);
	}
	while (groot->pile_b != NULL)
	{
		big_value = ft_index_big_value_b(groot);
		pos = ft_pos_big_value(groot, big_value);
		i = ft_lstsize(groot->pile_b);
		while (pos < i && big_value->index != groot->pile_b->index)
			rb(groot);
		while (pos >= i && big_value->index != groot->pile_b->index)
			rrb(groot);
		pa(groot);
	}
}

void	ft_algo_choice(t_list *groot)
{
	t_element	*big_value;
	int			i;

	big_value = ft_index_big_value(groot);
	i = ft_lstsize(groot->a);
	if (big_value->index == 2)
	{
		if (big_value->index > groot->a->index)
			sa(groot);
	}
	if (i == 1)
		exit(EXIT_SUCCESS);
	if (i <= 3)
	{
		ft_short_algo(groot);
	}
	else if (i <= 5)
		ft_short_algo2(groot);
	else if (i <= 100)
		ft_algo(groot, 20);
	else if (i > 100)
		ft_algo(groot, 35);
}
