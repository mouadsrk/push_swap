# include "push_swap.h"


void sa(t_stack **a ,char *str)
{
	t_stack *tmp;

	if(!a)
	{
		printf("erro\n");
		return;
	}
		

	write(1, str, ft_strlen(str));

	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void ss(t_stack **a,t_stack **b)
{
	sa(a , "sa\n");
	sa(b, "sb\n");
}

void pa(t_stack **a,t_stack **b ,char *str)
{
	t_stack *tmp;

	if(!*a)
	{
		printf("erro\n");
		return;
	}

	write(1, str, ft_strlen(str));
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp; 
}


void ra(t_stack **a ,char *str,int i)
{
	t_stack *tmp;
	t_stack *tmp2;

	if(!*a)
	{
		printf("erro\n");
		return;
	}
	if(i == 1)
	write(1, str, ft_strlen(str));
	tmp = *a;
	tmp2 = *a;
	*a = (*a)->next;
	while(tmp->next)
	tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void rr(t_stack **a,t_stack **b ,int i)
{
	if(i == 0)
	write(1,"rr\n",3);
	ra(a ,"ra\n",0);
	ra(b ,"rb\n",0);
}

void rra(t_stack **a ,char *str)
{
	t_stack *tmp;
	t_stack *tmp2;

	if(!*a)
	{
		printf("erro\n");
		return;
	}

	write(1, str, ft_strlen(str));
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
	rra(a, "rra\n");
	rra(b, "rrb\n");
}
