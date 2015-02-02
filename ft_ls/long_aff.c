#include "ft_ls.h"

static int	ft_get_bytes_max(t_list **targets, int *options)
{
    int		size;
    int		temp;
    t_list	*list;
    t_file	*file;

    size = 0;
    temp = 0;
    list = *targets;
    while (list)
    {
        file = list->content;
        if (O_HIDDEN || (!O_HIDDEN && !(ft_check_hidden(file->name))))
	    temp = file->stat->st_size;
        if (temp > size)
            size = temp;
	list = list->next;
    }
    return (size);
}

static int	*ft_get_sizes(t_list **targets, int *options)
{
    int		*size_max;

    size_max = malloc(sizeof(int) * 5);
    size_max[0] = ft_get_size_max(targets, options);
    size_max[1] = ft_size_ldir(targets, options);
    size_max[2] = ft_get_usr_max(targets, options);
    size_max[3] = ft_get_grp_max(targets, options);
    size_max[4] = ft_get_bytes_max(targets, options);
    return (size_max);
}

void		ft_aff_long(t_list **targets, int *options)
{
    t_list      *list;
    t_file	*file;
    int		*size_max;

    size_max = ft_get_sizes(targets, options);
    list = *targets;
    while (list)
    {
	file = list->content;
	if (O_HIDDEN || (!O_HIDDEN && !(ft_check_hidden(file->name))))
	{
	    ft_print_perms(file->stat);
	    ft_linkdir(file, size_max[1]);
	    ft_print_user(file, size_max[2], size_max[3]);
	    ft_blank_spaces(size_max[4], file->stat->st_size);
	    ft_putnbr(file->stat->st_size);
	    ft_putchar(' ');
	    ft_print_date(file->stat);
	    ft_putstr(file->name);
	    ft_putchar('\n');
	}
	list = list->next;
    }
}
