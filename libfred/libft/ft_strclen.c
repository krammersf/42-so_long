/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:48:49 by fde-carv          #+#    #+#             */
/*   Updated: 2023/08/21 15:59:52 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s && s[len] != c && s[len])
		len++;
	return (len);
}

/*
Essa função chamada ft_strclen é responsável por calcular o tamanho da
sequência de caracteres (string) s até o caractere c, ou até o final da string,
o que ocorrer primeiro. Vou explicar cada parte dessa função:

1. size_t ft_strclen(const char *s, char c): Isso define a função ft_strclen
com dois parâmetros. O primeiro parâmetro é um ponteiro para um caractere
(const char *s), que representa a string a ser analisada. O segundo parâmetro
é um caractere (char c), até o qual a contagem deve ser feita.

2. size_t len = 0;: Aqui, uma variável len é inicializada com o valor 0. Essa
variável será usada para contar o número de caracteres até o caractere c ou o
final da string.

3. while (s && s[len] != c && s[len]): Este é um loop while que verifica três
condições:
>> s: Verifica se o ponteiro para a string s não é nulo.
>> s[len] != c: Verifica se o caractere atual na posição len da string s não
   é igual a c.
>> s[len]: Verifica se o caractere atual na posição len da string s não é o
   caractere nulo de término de string.

4. O loop continua enquanto todas essas condições forem verdadeiras.

5. len++;: Dentro do loop, a variável len é incrementada em 1 a cada iteração,
o que significa que estamos avançando pela string.

6. return (len);: Depois que o loop termina, a função retorna o valor de len,
que representa o número de caracteres percorridos até o caractere c ou até o
final da string.

Em resumo, essa função percorre a string a partir do início até encontrar o
caractere especificado (c) ou o final da string, contando quantos caracteres
foram percorridos. Isso é útil para determinar o comprimento de uma substring
ou para verificar quantos caracteres há até um determinado ponto na string.
*/
