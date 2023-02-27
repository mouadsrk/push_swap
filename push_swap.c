/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:51:09 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 16:52:21 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	d;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	parse(argc, argv, &d);
	a = make_stack(d.str2);
	ft_free(d.str2, ft_word(d.str, ' '));
	free(d.str);
	duplicat_number(a);
	indice(a);
	sort_size(&a, &b, ft_lstsize(a));
	ft_lstclear(&a);
}
