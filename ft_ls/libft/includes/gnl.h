/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:16:05 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 13:08:02 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H

# define GNL_H

# include "libft.h"

# define BUFF_SIZE 10

int		get_next_line(int const fd, char **line);

char	*ft_strjoin_gnl(char const *s1, char const *s2);

char	*ft_strdup_gnl(const char *str);

#endif
