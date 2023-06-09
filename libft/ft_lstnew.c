/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:12:18 by dferjul           #+#    #+#             */
/*   Updated: 2023/06/05 23:34:57 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_element	*ft_lstnew(int value)
{
	t_element	*groot;

	groot = malloc(sizeof(t_list));
	if (!groot)
		return (NULL);
	groot->value = value;
	groot->next = NULL;
	return (groot);
}
