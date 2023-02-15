# include "push_swap.h"

void sa(t_stack *a)
{
	int i;

	i = a->content;
	a->content = a->next->content;
	a->next->content = i;
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

void pb(t_stack **a,t_stack **b)
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

int main ()
{
	t_stack *s;
	t_stack *t;


	s = ft_lstnew(2);
	ft_lstadd_back(&s,ft_lstnew(3));
	ft_lstadd_back(&s,ft_lstnew(4));
	t = s;
	while(t)
	{
		printf("%d ",t->content);
		t = t->next;
	}
	ra(&s);
	printf("\n");
	while(s)
	{
		printf("%d ",s->content);
		s = s->next;
	}

}

