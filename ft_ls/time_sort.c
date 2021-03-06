#include "ft_ls.h"

static int	ft_compare_time(t_list *list, t_list *list2)
{
    t_file	*file;
    t_file	*file2;

    file = list->content;
    file2 = list2->content;
    if (file->stat->st_mtime > file2->stat->st_mtime)
	return (0);
    else
	return (1);
}

void		ft_time_sort(t_list **targets)
{
    t_list	*list;
    t_list	*list2;
    t_list	*temp;
    int		to_sort; 

    to_sort = 1;
    while (to_sort)
    {
	to_sort = 0;
	list = *targets;
	while (list->next)
	{
	    list2 = list->next;
	    if (!(ft_compare_time(list, list2)))
	    {
		temp = list->content;
		list->content = list2->content;
		list2->content = temp;
		to_sort = 1;
	    }
	    list = list->next;
	}
    }
}
