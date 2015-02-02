#include "ft_ls.h"

static void     ft_check_targets(t_list **targets)
{
    t_list      *list;
    t_file      *file;

    file = malloc(sizeof(*file));
    file->stat = malloc(sizeof(t_stat));
    list = *targets;
    while (list)
    {
        if ((lstat(list->content, file->stat)) < 0)
	{
            ft_putstr("stat error\n"); //erreur
	    free(list->content);
	    list->content = NULL;
	}
        else
            list->content = ft_fill_stat(list->content);
        list = list->next;
    }
}

static t_data	*ft_init_data(void)
{
    int	    i;
    t_data  *data;

    i = 0;
    if (!(data = malloc(sizeof(*data))))
	return(NULL); // utiliser erno pour message erreur
    while (i < 5)
    {
	data->options[i] = 0;
	i++;
    }
    data->targets = NULL;
    return (data);
}

static void	ft_sort(t_list **targets, int *options)
{
    if (O_TIME)
	ft_time_sort(targets);
    else
	ft_alph_sort(targets);
    if (O_REVERSE)
	ft_rev_sort(targets);
}

static int	ft_ret_dir(t_list **targets, int *options, char **aff_dir)
{
    t_list	*list;

    list = *targets;
    if (list)
    {
	if (!(list->next) && O_RECURSIVE)
	{
	    *aff_dir = list->content;
	    return (1);
	}
	else
	    return (0);
    }
    else
    {
	if (O_RECURSIVE)
	{
	    *aff_dir = ".";
	    return (1);
	}
	else
	    return (1);
    }
}

int		main(int argc, char **argv)
{
    t_data	*data;
    char	*aff_dir;

    data = ft_init_data();
    aff_dir = NULL;
    if (argc > 1)
	ft_browse_arg(data, argv);
    if (data->targets == NULL && (ft_ret_dir(&(data->targets), data->options, &aff_dir)))
    {
	ft_get_files(&(data->targets), "./");
	ft_check_targets(&(data->targets));
//	ft_clean_list(&(data->targets), data->options);
	ft_exec_ls(data, 0, aff_dir, NULL);
    }
    else
    {
	ft_check_targets(&(data->targets));
//	ft_clean_list(&(data->targets), data->options);
	ft_sort(&(data->targets), data->options);
	ft_rec_ls(data, 0, NULL, NULL);
    }
    return (0);
}
