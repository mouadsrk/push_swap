/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:35:51 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/16 05:27:56 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void indice(t_stack *a)
{
	t_stack *tmp;
	t_stack *tmp2;
	
	tmp2 = a;
	while(a)
	{
		tmp = tmp2;
		while(tmp)
		{
			if(a->content >= tmp->content )
				a->pos += 1;
			tmp = tmp->next;
		}
		a = a->next;
	}
}


