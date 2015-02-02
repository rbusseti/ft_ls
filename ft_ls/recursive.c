#include "ft_ls.h"

static void ft_get_stats(t_list **new, char *path)
{
    t_list	*list;
    char	*new_path;

    list = *new;
    while (list)
    {
	new_path = ft_strjoin(path, "/");
	list->content = ft_fill_stat(ft_strjoin(new_path, list->content));
	list = list->next;
    }
}

static int ft_check_rep(t_file *file)
{
    int		i;
    char	*str;

    str = file->name;
    i = 0;
    while (str[i])
	i++;
    while (str[i] != '/' && i > 0)
	i--;
    if (i > 0)
	i++;
    if ((ft_strcmp(str + i, ".")) == 0)
	return (0);
    else if ((ft_strcmp(str + i, "..")) == 0)
	return (0);
    else
	return (1);
}

static t_data	*ft_return_data(t_list **targets, int *options)
{
    t_data	*data;

    data = malloc(sizeof(*data));
    data->targets = *targets;
    data->options[0] = options[0];
    data->options[1] = options[1];
    data->options[2] = options[2];
    data->options[3] = options[3];
    data->options[4] = options[4];
    return (data);
}

void		ft_rec_ls(t_data *data, int line, char *aff_dir, char *path)
{
    t_list	*list;
    t_list	*new;
    t_file	*file;
    char	*new_path;

    new = NULL;
    list = data->targets;
    while (list)
    {
	file = list->content;
	if ((file->stat->st_mode & S_IFDIR) && ft_check_rep(file))
	{
	    if (path == NULL)
		new_path = ft_strjoin("./", file->name);
	    else
		new_path = ft_strdup(file->name);
	    ft_get_files(&new, new_path);
	    ft_get_stats(&new, new_path);
	    if (line != 0 || list->next)
		aff_dir = ft_strdup(file->name);
	    ft_exec_ls(ft_return_data(&new, data->options), line, aff_dir, new_path);
	    line = 1;
	}
	list = list->next;
    }
}
