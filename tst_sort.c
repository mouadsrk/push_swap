/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:02:58 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/19 07:33:16 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// void check_size(t_stack **a,int size)
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


// void sort_100(t_stack **a,t_stack **b ,int size)
// {
// 	t_stack *tmp;
	
// 	int	i ;
	
// 	check_size(a , size);
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
// 	tmp = (*a);



#include<stdio.h>

int main ()
{

	int mid , chunck = 39 , size = 26;
	
	if(chunck <= 19)
		mid = size / 2;
	if(chunck > size && chunck > 19)
		mid = ((chunck - 20) + size) / 2     ;
	if ((chunck <= size && chunck > 19))
		mid = chunck - 10 ;

    printf("mid = %d\n",mid);
}