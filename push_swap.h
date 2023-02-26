#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"


typedef struct stract
{
    int     chunck;
    int     holt_first;
    int     holt_second;
    int     first_move;
    int     seconde_move;
    char    *str;
    char	**str2;
    int     num;
    int     tmp;
    int     mid;

} t_data;

void sa(t_stack **a ,char *str);
void ss(t_stack **a,t_stack **b);
void pa(t_stack **a,t_stack **b , char *);
void ra(t_stack **a,char *str, int i);
void rr(t_stack **a,t_stack **b);
void rra(t_stack **a, char *str);
void rrr(t_stack **a,t_stack **b);
void indice(t_stack *a);
void sort_size(t_stack **a,t_stack **b,int i);
int  check_sort(t_stack *a);
void sort_3(t_stack **a);
void sort_5(t_stack **a,t_stack **b);
void sort_4(t_stack **a,t_stack **b);
int min_pos(t_stack *a);
int max_pos(t_stack *a);
int get_pos(t_stack *a,int pos);

#endif

