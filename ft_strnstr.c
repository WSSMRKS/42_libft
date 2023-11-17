/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:21:31 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/17 21:17:12 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);
char	*ft_while(char *tmpstr, char *tmpfnd);
int		ft_comp(char *tmpstr, char *tmpfnd);
int		ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (*str != '\0')
	{
		strlen++;
		str++;
	}
	return (strlen);
}

int	ft_comp(char *tmpstr, char *tmpfnd)
{
	char	*tmpcmp1;
	char	*tmpcmp2;
	int		suc;
	int		len;
	int		l;

	tmpcmp1 = tmpstr;
	tmpcmp2 = tmpfnd;
	len = ft_strlen(tmpfnd);
	l = 0;
	while (*tmpcmp1 == *tmpcmp2 && *tmpcmp1 != '\0')
	{
		tmpcmp1++;
		tmpcmp2++;
		l++;
	}
	if (l == (len))
		suc = 1;
	else
		suc = 0;
	return (suc);
}

char	*ft_while(char *tmpstr, char *to_find)
{
	char	*ret;
	int		success;
	char	*tmpfnd;

	success = 0;
	ret = (void *) 0;
	while (*tmpstr != '\0' && success != 1)
	{
		tmpfnd = to_find;
		success = ft_comp(tmpstr, tmpfnd);
		if (success == 0)
			tmpstr++;
	}
	if (success == 1)
		ret = tmpstr;
	return (ret);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmpstr;
	char	*needle;

	tmpstr = str;
	needle = to_find;
	if (*to_find == '\0')
		return (str);
	else
		needle = ft_while(tmpstr, to_find);
	return (needle);
}

 char *
     strnstr(const char *big, const char *little, size_t len);