/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: phillebr <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/08 18:24:38 by phillebr		  #+#	#+#			 */
/*   Updated: 2024/02/08 18:28:57 by phillebr         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
			*(str + i) += 32;
		}
		i++;
	}
	return (str);
}
