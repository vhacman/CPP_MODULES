/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/17 17:29:30 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** Funzione helper per l'algoritmo BSP
** Scopo: Determina da quale lato di una linea si trova un punto

** Ritorna: Il prodotto scalare (cross product) tra i due vettori
**   - Se > 0: p1 si trova a sinistra della linea p2-p3
**   - Se < 0: p1 si trova a destra della linea p2-p3
**   - Se = 0: p1 si trova sulla linea p2-p3
**
** Utilizzo nella BSP:
**   Se il punto si trova sempre dalla stessa parte rispetto a tutti
**   e tre i lati del triangolo, allora è DENTRO il triangolo.
*/
static Fixed	sign(Point const &p1, Point const &p2, Point const &p3) {
	Fixed diffx1;
	Fixed diffy2;
	Fixed diffx2;
	Fixed diffy1;

	diffx1 = p1.getX() - p3.getX();
	diffy2 = p2.getY() - p3.getY();
	diffx2 = p2.getX() - p3.getX();
	diffy1 = p1.getY() - p3.getY();
	return (diffx1 * diffy2 - diffx2 * diffy1);
}

/*
** bsp - Binary Space Partitioning
**
** Determina se un punto si trova all'interno di un triangolo utilizzando
** il metodo del prodotto vettoriale (cross product).
**
** ALGORITMO:
** 1. Calcola il prodotto vettoriale tra il punto e ciascun lato del triangolo
** 2. Verifica se il punto giace su un bordo o vertice (valore = 0)
** 3. Controlla se tutti i prodotti vettoriali hanno lo stesso segno
**
** LOGICA:
** - Se un punto è DENTRO il triangolo, si trova dallo STESSO LATO rispetto
**   a tutti e tre i lati del triangolo
** - Questo significa che tutti i prodotti vettoriali avranno lo stesso segno:
**   * Tutti POSITIVI (orientamento antiorario)
			OPPURE
**   * Tutti NEGATIVI (orientamento orario)

** - Se i segni sono MISTI (alcuni positivi, altri negativi), il punto è FUORI
** - Se un valore è ZERO, il punto è su un lato o vertice → considerato FUORI
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1;
	Fixed	d2;
	Fixed	d3;
	bool	has_neg;
	bool	has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);
	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);
	has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));
	return !(has_neg && has_pos);
}
