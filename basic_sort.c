/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:28:32 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/18 23:51:44 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void sort_3(t_stack **a)
{
	int i1;
	int i2;
	int i3;
	
	if(!*a)
		return;
	i1 = (*a)->content;
	i2 = (*a)->next->content;
	i3 = (*a)->next->next->content;
	if((i1 > i2 && i1 < i3) || (i1 > i2 && i2 > i3) || (i1 < i3 && i3 < i2))
		sa(a ,"sa \n");
	i1 = (*a)->content;
	i2 = (*a)->next->content;
	i3 = (*a)->next->next->content;
	if(i1 > i3 && i3 > i2)
		ra(a , "ra\n");
	if(i1 < i2 && i1> i3)
		rra(a , "rra");
}

void sort_4_nor(t_stack **a,t_stack **b)
{
	int i1;
	int i2;
	int i3;
	int i4;

	i1 = (*a)->pos;
	i2 = (*a)->next->pos;
	i3 = (*a)->next->next->pos;
	i4 = (*a)->next->next->next->pos;
	if(i3 == 0)
	{
		ra(a ,"ra \n");
		ra(a , "ra \n");
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a,"pa \n");
	}
	else if(i4 == 0)
	{
		rra(a, "rra \n");
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a ,"pa \n");
	}
}


void sort_4(t_stack **a,t_stack **b)
{
	int i1;
	int i2;
	int i3;
	int i4;

	i1 = (*a)->pos;
	i2 = (*a)->next->pos;
	i3 = (*a)->next->next->pos;
	i4 = (*a)->next->next->next->pos;
	if(i1 == 0)
	{
		pa(a,b , "pb \n");
		sort_3(a);
		pa(b,a, "pa \n");
	}
	else if(i2 == 0)
	{
		sa(a, "sa\n");
		pa(a,b , "pb \n");
		sort_3(a);
		pa(b,a ,"pa \n");
	}
	else
	sort_4_nor(a,b);
}

int min_pos(t_stack *a)
{
	t_stack *tmp;
	int i;
	
	tmp = a;
	i = tmp->pos;
	while(tmp)
	{
		if(i > tmp->pos)
			i = tmp->pos;
		tmp = tmp->next;
	}
	return i;
}

int max_pos(t_stack *a)
{
	t_stack *tmp;
	int i;
	
	tmp = a;
	i = tmp->pos;
	while(tmp)
	{
		if(i < tmp->pos)
			i = tmp->pos;
		tmp = tmp->next;
	}
	return i;
}

int get_pos(t_stack *a,int pos)
{
	int i;

	i = 0;
	while(a)
	{
		if(a->pos == pos)
			return i;
		a = a->next;
		i++;
	}
	return -1;
}


void sort_5(t_stack **a,t_stack **b)
{
	while(ft_lstsize(*a) > 3)
	{
		if (get_pos(*a ,min_pos(*a)) >= ft_lstsize(*a) /2)
			while((*a)->pos != min_pos(*a))
				rra(a ,"rra \n");   
		else if (get_pos(*a ,min_pos(*a)) < ft_lstsize(*a) /2)
			while((*a)->pos != min_pos(*a))
				ra(a, "ra \n");   
		if((*a)->pos == min_pos(*a)) 
			pa(a,b, "pb \n");
	}
	sort_3(a);
	while(*b)
		pa(b,a , "pa \n");
}






// next modification

int get_chunck(t_stack *a,t_data *d)
{
	int i;

	d->holt_first = -1;
	d->holt_second = -1;
	i = 0;
	while(a)
	{
		if(a->pos <= d->chunck && d->holt_first == -1 )
		{
			d->holt_first = a->pos;
			d->holt_second = a->pos;
		}
		else if(a->pos <= d->chunck && d->holt_first != -1 )
			d->holt_second = a->pos;
		i++;
		a = a->next;
	}
	return i;
}


int push_b(t_data *d, t_stack **a ,  t_stack **b)
{
	if(!*a)
		return 1;		
	get_chunck(*a,d);	
		if(d->holt_second == -1 && d->holt_first == -1)
			return 1;
	d->first_move = get_pos(*a,d->holt_first);
	d->seconde_move = ft_lstsize(*a) - get_pos(*a,d->holt_first) - 1;
	if(d->first_move <= d->seconde_move )
	{
		while((*a)->pos != d->holt_first)
			ra(a,"ra\n");
			if((*a)->pos == d->holt_first)
			{
				printf("push pos = %d\n",(*a)->pos);
				pa(a , b, "pb\n");
				if((*b)->pos >= d->chunck / 2)
					if(*b && (ft_lstsize(*b)) != 1)
						ra(b,"rb\n");
			}
		}
		else
		{
		while((*a)->pos != d->holt_second && d->holt_second != -1)
				rra(a,"rra\n");
		if((*a)->pos == d->holt_second)
		{
			printf("push pos = %d\n",(*a)->pos);
			pa(a , b, "pb\n");
				if((*b)->pos >= d->chunck / 2 && (ft_lstsize(*b)) != 1)
				{
					ra(b,"rb\n");
				}
		}
		}
		return 0;
}


void sort_100(t_stack **a,t_stack **b ,int size)
{
	t_data d;
	t_stack *tmp;
	int i;
	
	d.chunck = size / 4 - 1;
	printf("c%d\n",d.chunck);
	while(*a)
	{
		i = 0;
		while(i == 0)
		{
			i = push_b(&d,a,b);
				tmp = *a;
			// while(tmp)
			// {
			// 	printf("pos = %d valeur  %d\n",tmp->pos, tmp->content);
			// 	tmp = tmp->next;
			// }
			printf("\n");
		}
		d.chunck += size / 5 - 1;
	}

	while(*a)
		pa(a,b,"pb\n");
	// tmp = *b;
	// while(tmp)
	// {
	// 	printf("%d\n",tmp->pos);
	// 	tmp = tmp->next;
	// }
	
}






void sort_size(t_stack **a,t_stack **b,int i)
{
	t_stack *tmp;
	if(i < 3)
		sa(a , "sa \n ");
	if(i <= 3)
		sort_3(a);
	else if(i <= 4)
		sort_4(a,b);    
	else if(i <= 5)
		sort_5(a,b);
	else  if (i <= 100)
		sort_100(a,b ,i);
	
	// else if (i >= 100)
	//     sort_500();
}













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
	
	
// }
