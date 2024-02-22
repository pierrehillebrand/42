/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: phillebr <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/08 18:33:31 by phillebr		  #+#	#+#			 */
/*   Updated: 2024/02/11 10:27:45 by phillebr         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

int	is_alphanum(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		return (1);
	else if (*str >= 'A' && *str <= 'Z')
		return (1);
	else if (*str >= '0' && *str <= '9')
		return (1);
	else
		return (0);
}

int	is_alpha(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
	{
		return (1);
	}
	else if (*str >= 'a' && *str <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	change(char *str, int a)
{
	if (a == 0)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
	}
	else
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 32;
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alpha(str + i))
		{
			if (i == 0 || !is_alphanum(str + i - 1))
			{
				change(str + i, 1);
			}
			else
			{
				change(str + i, 0);
			}
		}
		i++;
	}
	return (str);
}
