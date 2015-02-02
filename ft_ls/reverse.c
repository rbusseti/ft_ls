#include "ft_ls.h"

void	ft_rev_sort(t_list **targets)
{
    t_list	*list;
    t_list	*temp;
    t_list	*temp2;

    list = *targets;
    while(list)
    {
	temp = list->next;
	list->next = list->prev;
	list->prev = temp;
	temp2 = list;
	list = temp;
    }
    *targets = temp2;
}
