#include "ft_ls.h"

static void	ft_print_name(char *str, int *options)
{
    int		i;

    if (!O_HIDDEN)
    {
	if (ft_check_hidden(str))
	    return;
    }
    i = ft_strlen(str);
    while (str[i] != '/' && i != 0)
	i--;
    if (i != 0)
	i++;
    while (str[i])
    {
	ft_putchar(str[i]);
	i++;
    }
    ft_putchar('\n');
}

void		ft_aff_ls(t_list **targets, int line_break, char *aff_dir, int *options)
{
    t_list	*list;
    t_file	*file;

    list = *targets;
    if (line_break)
	ft_putchar('\n');
    if (aff_dir)
    {
	ft_putstr(aff_dir);
	ft_putchar(':');
	ft_putchar('\n');
    }
    if (O_LONG)
	ft_aff_long(targets, options);
    else
	while (list)
	{
	    file = list->content;
	    ft_print_name(file->name, options);
	    list = list->next;
	}
}
