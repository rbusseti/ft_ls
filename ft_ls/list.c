#include "ft_ls.h"

void	ft_free_link(t_list *list)
{
    free(list->content->stat);
    free(list->content->name);
    if (temp->prev)
	temp->prev->next = temp->next;
    if (temp->next)
	temp->next->prev = temp->prev;
    free(temp);
}
