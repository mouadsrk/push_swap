/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:28:32 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/25 02:20:28 by mserrouk         ###   ########.fr       */
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
		sa(a ,"sa\n");
	i1 = (*a)->content;
	i2 = (*a)->next->content;
	i3 = (*a)->next->next->content;
	if(i1 > i3 && i3 > i2)
		ra(a ,"ra\n",1);
	if(i1 < i2 && i1> i3)
		rra(a , "rra\n");
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
		ra(a ,"ra\n",1);
		ra(a , "ra\n",1);
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a,"pa\n");
	}
	else if(i4 == 0)
	{
		rra(a, "rra\n");
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a ,"pa\n");
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
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a, "pa\n");
	}
	else if(i2 == 0)
	{
		sa(a, "sa\n");
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a ,"pa\n");
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
				rra(a ,"rra\n");
		else if (get_pos(*a ,min_pos(*a)) < ft_lstsize(*a) /2)
			while((*a)->pos != min_pos(*a))
				ra(a,"ra\n",1);
		if((*a)->pos == min_pos(*a))
			pa(a,b, "pb\n");
	}
	sort_3(a);
	while(*b)
		pa(b,a , "pa\n");
}


void get_chunck(t_stack *a,t_data *d)
{
	d->holt_first = -1;
	d->holt_second = -1;
	while(a)
	{
		if((a->pos <= d->chunck && d->holt_first == -1))
		{
			d->holt_first = a->pos;
			d->holt_second = a->pos;
		}
		else if((a->pos <= d->chunck && d->holt_first != -1))
			d->holt_second = a->pos;
		a = a->next;
	}
}



int push_b_data(t_data *d, t_stack **a ,  t_stack **b)
{
	if(!*a)
		return 1;
	get_chunck(*a,d);
	if(d->holt_second == -1 && d->holt_first == -1)
		return 1;
	d->first_move = get_pos(*a,d->holt_first);
	d->seconde_move = ft_lstsize(*a) - get_pos(*a,d->holt_second) + 1;
	return 0;
}

void calcule_chunk_and_middle(t_data *d ,t_stack **a ,t_stack **b , int i)
{
	d->tmp = d->chunck;
    if(ft_lstsize(*a) <= 100)
		d->num = i  / 40 +  i %  40;
    if(ft_lstsize(*a) <= 250 && ft_lstsize(*a) >= 100)
		d->num = i  / 15 +  i % 15;
	d->chunck = d->chunck + d->num;
	d->mid = d->tmp + d->num / 2;
}


int  middle(t_data d ,t_stack **a ,t_stack **b , int i)
{
	d.tmp = d.chunck;
    if(ft_lstsize(*a) <= 100)
		d.num = i  / 40 +  i %  40;
    else if(ft_lstsize(*a) <= 250 && ft_lstsize(*a) >= 100)
		d.num = i  / 15 +  i % 15;
	d.chunck = d.chunck + d.num;
	return (d.tmp + d.num / 2);
}

// new
int push_b(t_data *d, t_stack **a ,  t_stack **b , int i)
{
	int m ;

	m = push_b_data(d,a,b);
	if(m == 1)
		return 1;
	// printf(">>>>>>>>>>\n");
	// printf("chunk = %d\n",d->chunck);
	// printf("mid = %d\n",d->mid);
	// printf("first = %d\n",d->holt_first);
	// printf("second = %d\n",d->holt_second);
	// printf("first move = %d\n",d->first_move);
	// printf("second move = %d\n",d->seconde_move);
	// printf("a = %d\n",(*a)->pos);
	while((*a)->pos != d->holt_first && (d->holt_first != d->holt_second || d->first_move <= d->seconde_move))
	{
				ra(a,"ra\n",1);
	}
	while((*a)->pos != d->holt_second && (d->holt_first == d->holt_second  && d->first_move > d->seconde_move))
				rra(a,"rra\n");
	if((*a)->pos == d->holt_first || (*a)->pos == d->holt_second)
	{
		// printf("pa = %d\n",(*a)->pos);
		pa(a , b, "pb\n");
	}
	if (push_b_data(d,a,b) == 0 && (*b)->pos <= d->mid && ft_lstsize(*b) > 2 && (*a)->pos != d->holt_first)
	{
		// printf("2 first = %d\n",d->holt_first);
		// printf("2 second = %d\n",d->holt_second);
		// printf("2 first move = %d\n",d->first_move);
		// printf("2 second move = %d\n",d->seconde_move);
		// printf("b = %d\n",(*b)->pos);
		if(d->holt_first != d->holt_second)
		{
			// printf("rr\n");
			rr(a,b,0);
		}
		else if(d->first_move < d->seconde_move && d->holt_first == d->holt_second)
		{
			// printf("rr\n");
			rr(a,b,0);
		}
		else if(d->first_move > d->seconde_move && d->holt_first == d->holt_second)
		{
			// printf("rb\n");
			ra(b,"rb\n",1);
		}
	}
	else if(*a == NULL)
			return 1;	
	else if ((*b)->pos <= d->mid && ft_lstsize(*b) > 2 && (*a)->pos != d->holt_first)
	{
		if((*b)->pos <= middle(*d,a ,b ,i) )
		{
		// printf("2 first = %d\n",d->holt_first);
		// printf("2 second = %d\n",d->holt_second);
		// printf("2 first move = %d\n",d->first_move);
		// printf("2 second move = %d\n",d->seconde_move);
		// printf("next mide = %d\n",middle(*d,a ,b ,i));
		// printf("b = %d\n",(*b)->pos);
			if(d->first_move <= d->seconde_move)
			{
				// printf("rr\n");
					rr(a,b,0);
			}
			else if(d->first_move > d->seconde_move)
			{
				// printf("rb\n");
				ra(b,"rb\n",0);
			}
		}
	}
	// printf(">>>>>>>>>\n");
	return 0;
}

void get_stak_a(t_stack *b,t_data *d)
{
	d->holt_first = -1;
	d->holt_second = -1;
	d->holt_first = max_pos(b);
	d->holt_second = min_pos(b);
	while(b)
	{
		if(d->holt_second < b->pos && b->pos != d->holt_first)
			d->holt_second = b->pos;
		b = b->next;
	}
}


void check_top(t_data *d,t_stack **a,t_stack **b)
{
	if(d->first_move <= d->seconde_move)
		{
			while ((*b)->pos != d->holt_second)
			{
				if((*b)->pos == d->holt_first)
					pa(b,a,"pa\n");
				if((*b)->pos == d->holt_second)
					break;
				ra(b,"rb\n",1);
			}
			if((*b)->pos == d->holt_second)
				pa(b,a,"pa\n");
		}
	else if(d->first_move > d->seconde_move)
	{
		while ((*b)->pos != d->holt_first)
		{
			if((*b)->pos == d->holt_second)
				pa(b,a,"pa\n");
			if((*b)->pos == d->holt_first)
				break;
			ra(b,"rb\n",1);
		}
		if((*b)->pos == d->holt_first)
			pa(b,a,"pa\n");
			sa(a,"sa\n");
	}
}

void check_down(t_data *d,t_stack **a,t_stack **b)
{
	if(d->first_move >= d->seconde_move)
		{
			while ((*b)->pos != d->holt_second)
			{
				if((*b)->pos == d->holt_first)
					pa(b,a,"pa\n");
				if((*b)->pos == d->holt_second)
					break;
				rra(b,"rrb\n");
			}
			if((*b)->pos == d->holt_second)
				pa(b,a,"pa\n");
		}
	else if(d->first_move < d->seconde_move)
	{
		while ((*b)->pos != d->holt_first)
		{
			if((*b)->pos == d->holt_second)
					pa(b,a,"pa\n");
			if((*b)->pos == d->holt_first)
				break;
			rra(b,"rrb\n");
		}
		if((*b)->pos == d->holt_first)
				pa(b,a,"pa\n");
			sa(a,"sa\n");
	}
}

void check_diver1(t_data *d,t_stack **a,t_stack **b)
{
	if(d->first_move <= ft_lstsize(*b) - d->seconde_move + 2)
	{
		while ((*b)->pos != d->holt_first)
			ra(b,"rb\n",1);
		if((*b)->pos == d->holt_first)
			pa(b,a,"pa\n");
		while ((*b)->pos != d->holt_second)
			rra(b,"rrb\n");
		if((*b)->pos == d->holt_second)
			pa(b,a,"pa\n");
	}
	else if (d->first_move > ft_lstsize(*b) - d->seconde_move + 2)
	{
		while ((*b)->pos != d->holt_second)
			rra(b,"rrb\n");
		if((*b)->pos == d->holt_second)
			pa(b,a,"pa\n");
		while ((*b)->pos != d->holt_first)
			ra(b,"rb\n",1);
		if((*b)->pos == d->holt_first)
				pa(b,a,"pa\n");
			sa(a,"sa\n");
	}
}

void check_diver2(t_data *d,t_stack **a,t_stack **b)
{
	if (d->seconde_move <= ft_lstsize(*b) - d->first_move + 2)
	{
		while ((*b)->pos != d->holt_second )
			ra(b,"rb\n",1);
		if((*b)->pos == d->holt_second)
			pa(b,a,"pa\n");
		while ((*b)->pos != d->holt_first)
			rra(b,"rrb\n");
		if((*b)->pos == d->holt_first)
				pa(b,a,"pa\n");
		if(d->holt_second != d->holt_first)
				sa(a,"sa\n");
	}
	else if(d->seconde_move > ft_lstsize(*b) - d->first_move + 2)
	{
		while((*b)->pos != d->holt_first)
			rra(b,"rrb\n");
		if((*b)->pos == d->holt_first)
			pa(b,a,"pa\n");
		while ((*b)->pos != d->holt_second)
			ra(b,"rb\n",1);
		if((*b)->pos == d->holt_second)
			pa(b,a,"pa\n");
	}
}


void push_a(t_data *d,t_stack **a,t_stack **b)
{
	int size;
	if(!*b)
		return ;
	get_stak_a(*b,d);
	if(d->holt_second == -1 && d->holt_first == -1)
		return ;
	if(d->holt_second == d->holt_first)
	{
		pa(b,a,"pa\n");
		return ;	
	}
	d->first_move = get_pos(*b,d->holt_first);
	d->seconde_move = get_pos(*b,d->holt_second);
	size = ft_lstsize(*b);
	if (d->first_move <= size /2 && d->seconde_move <= size /2)
		check_top(d,a,b);
	else if (d->first_move >= size /2 && d->seconde_move >= size /2)
		check_down(d,a,b);
	else if(d->first_move <= size /2 && d->seconde_move >= size /2)
		check_diver1(d,a,b);
	else if(d->first_move >= size /2 && d->seconde_move <= size /2)
		check_diver2(d,a,b);
}



void sort_100(t_stack **a,t_stack **b, int i)
{
	t_data d;
	int m;
	d.chunck = -1;
	d.num = i  / (9) +  i % (9) ;

	while(*a)
	{
		calcule_chunk_and_middle(&d ,a ,b , i);
		m = 0;
		while(!m)
		{
			m = push_b(&d,a,b ,i);
		}
	}

	// t_stack *tmp;

	// tmp = *b;
	// while(tmp)
	// {
	// 	printf("%d\n",tmp->pos);
	// 	tmp = tmp->next;
	// }
	// int k=0;
	while( (*b)) 
	{
		push_a(&d,a,b);
	}
}






void sort_size(t_stack **a,t_stack **b,int i)
{
	t_stack *tmp;
	if(i < 3)
		sa(a , "sa\n ");
	if(i <= 3)
		sort_3(a);
	else if(i <= 4)
		sort_4(a,b);
	else if(i <= 5)
		sort_5(a,b);
	else  if (i  > 5)
		sort_100(a,b ,i);
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
