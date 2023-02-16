# include "push_swap.h"

void sa(t_stack *a)
{
	int i;

	i = a->content;
	a->content = a->next->content;
	a->next->content = i;
	i = a->pos;
	a->pos = a->next->pos;
	a->next->pos = i;
}

void ss(t_stack *a,t_stack *b)
{
	sa(a);
	sa(b);
}

void pa(t_stack **a,t_stack **b)
{
	t_stack *tmp;

	if(!*a)
		return;
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp; 
}


void ra(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp2;

	if(!*a)
		return;
	tmp = *a;
	tmp2 = *a;
	*a = (*a)->next;
	while(tmp->next)
	tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void rr(t_stack **a,t_stack **b)
{
	ra(a);
	ra(b);
}

void rra(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp2;

	if(!*a)
		return;
	tmp = *a;
	tmp2 = *a;
	while(tmp->next)
	tmp = tmp->next;
	while(tmp2->next != tmp)
	tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *a;
	*a = tmp;
}

void rrr(t_stack **a,t_stack **b)
{
	rra(a);
	rra(b);
}

