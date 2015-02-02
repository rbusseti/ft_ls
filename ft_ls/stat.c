#include "ft_ls.h"

t_file	*ft_fill_stat(char *name)
{
    t_stat	*stat;
    t_file	*file;
    char	*str;

    stat = malloc(sizeof(*stat));
    file = malloc(sizeof(*file));
    if ((lstat(name, stat)) < 0)
	stat = NULL;
    file->stat = stat;
    str = ft_strdup(name);
    file->name = str;
    free(name);
    return (file);
}
