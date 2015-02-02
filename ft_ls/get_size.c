#include "ft_ls.h"

int	    ft_get_size_max(t_list **targets, int *options)
{
    t_list      *list;
    t_file      *file;
    int         size_max;
    int         temp;

    size_max = 0;
    temp = 0;
    list = *targets;
    while (list)
    {
        file = list->content;
        if (!O_HIDDEN)
        {
            if (!(ft_check_hidden(file->name)))
                temp = ft_strlen(file->name);
        }
        else
            temp = ft_strlen(file->name);
        if (temp > size_max)
            size_max = temp;
        list = list->next;
    }
    return (size_max);
}

int	    ft_get_usr_max(t_list **targets, int *options)
{
    t_list	*list;
    t_file	*file;
    int		size_max;
    int		temp;

    size_max = 0;
    temp = 0;
    list = *targets;
    while (list)
    {
	file = list->content;
	if (!O_HIDDEN)
	{
	    if (!(ft_check_hidden(file->name)))
		temp = ft_strlen(ft_get_uid(file));
	}
	else
	    temp = ft_strlen(ft_get_uid(file));
	if (temp > size_max)
	    size_max = temp;
	list = list->next;
    }
    return (size_max);
}

int	    ft_get_grp_max(t_list **targets, int *options)
{
    t_list	*list;
    t_file	*file;
    int		size_max;
    int		temp;

    size_max = 0;
    temp = 0;
    list = *targets;
    while (list)
    {
	file = list->content;
	if (!O_HIDDEN)
	{
	    if (!(ft_check_hidden(file->name)))
		temp = ft_strlen(ft_get_grid(file));
	}
	else
	    temp = ft_strlen(ft_get_grid(file));
	if (temp > size_max)
	    size_max = temp;
	list = list->next;
    }
    return (size_max);
}

int	    ft_get_dir_nbr(t_file *file)
{
    DIR		*fd;
    t_dirent	*dirent;
    int		size;

    size = 0;
    if (!(fd = opendir(file->name)))
    {
	ft_putstr("tu te trompe bouffon: ");
	ft_putendl(file->name);
    }
    while ((dirent = readdir(fd)) != NULL)
    {
	if (dirent->d_type == DT_DIR)
	    size++;
    }
    closedir(fd);
    return (size);
}

int	    ft_size_ldir(t_list **targets, int *options)
{
    int         size;
    int         temp;
    t_file      *file;
    t_list      *list;

    size = 0;
    temp = 0;
    list = *targets;
    while (list)
    {
        file = list->content;
	if (O_HIDDEN || (!O_HIDDEN && !(ft_check_hidden(file->name))))
	{
	    if (file->stat->st_mode & S_IFDIR)
		temp = ft_get_dir_nbr(file);
	    else
		temp = file->stat->st_nlink;
	}
	if (temp > size)
	    size = temp;
	list = list->next;
    }
    return (size);
}
