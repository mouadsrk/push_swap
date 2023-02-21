/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:02:58 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/21 03:17:54 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"


// void check_size(t_stack **a)
// {
// 	t_stack *tmp;
// 	t_stack *tmp2;
	
// 	tmp = *a;
// 	while(tmp)
// 	{
// 		tmp2 = *a;
// 		while(tmp2 != tmp->next)
// 		{
// 			if(tmp->content >= tmp2->content)
// 				tmp->log += 1;
// 			tmp2 = tmp2->next;
// 		}
// 		tmp = tmp->next;
// 	}	
// }

// void make_list(t_stack **a)
// {
// 	t_stack *tmp,*tmp2;
	
// 	int	i ;
	
// 	check_size(a);
// 	*a = ft_lstlast(*a);
// 	i = (*a)->log - 1;
// 	while((*a)->previous)
// 	{
// 		tmp = *a;
// 		while(tmp->previous)
// 		{
// 			if((*a)->log < tmp->log && tmp->log <= i)
// 			{
// 				(*a)->dis = 0;
// 				break;
// 			}
// 			tmp = tmp->previous;
// 		}
// 		if((*a)->dis == 1)
// 			i = (*a)->log - 1;
// 		tmp = (*a);
// 		while(tmp->previous)
// 		{	
// 			if((*a)->dis == 1 && (*a)->content < tmp->content && (*a)->log >= tmp->log )
// 				(tmp)->dis = 0;
// 			tmp = tmp->previous;
// 		}
// 		(*a) =(*a)->previous;
// 	}
// 	*a = ft_lstfirst(*a);
	// tmp2 = *a;
	// while(tmp2)
	// {
	// 	printf("log = %d dis = %d content %d\n",tmp2->log,tmp2->dis,tmp2->content);
	// 	tmp2= tmp2->next;
	// }
// }


// void a_rotating_direction(t_stack **a, t_stack **b)
// {
// 	if((*b)->pos > max_pos((*a)))
// 		return;
// 	else if ((*b)->pos < max_pos((*a)))
// 	{	
// 	 	if(((*b)->pos > (*a)->pos) && ((*b)->content > ft_lstlast(*a)->content))
// 			return;	
// 		else if((((*b)->pos > (*a)->pos)) && ((*b)->content < ft_lstlast(*a)->content))
// 		{
// 				while((*b)->content < ft_lstlast(*a)->content)
// 					rra(a,"rra\n");
// 		}
// 	}
// }



// int main ()
// {
// 	int num ;
// 	int j ;
// 	int d;
// 	num = 500 / 9 + 500 % 9 - 1;
// 	j = 1;
// 	d = j * num;
// 	while(j < 500 / num + 1)
// 	{
// 		printf( "c%d\n",j * num);
// 	printf( "%d\n",num / 2 + (j - 1) * num);
// 	j++;
// 	}
// }