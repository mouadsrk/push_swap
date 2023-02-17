#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"



typedef struct stract
{
    int     i;
    int     size;
    char    *num;
} t_data;

void sa(t_stack *a);
void ss(t_stack *a,t_stack *b);
void pa(t_stack **a,t_stack **b);
void ra(t_stack **a);
void rr(t_stack **a,t_stack **b);
void rra(t_stack **a);
void rrr(t_stack **a,t_stack **b);
void indice(t_stack *a);
void sort_size(t_stack **a,t_stack **b,int i);

#endif



