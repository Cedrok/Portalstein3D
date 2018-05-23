/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambda_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bspindle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:00:50 by bspindle          #+#    #+#             */
/*   Updated: 2018/01/12 13:09:53 by bspindle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_vect_d3	lambda_product_d3(double lambda, t_vect_d3 vector)
{
	t_vect_d3	result;

	result.x = lambda * vector.x;
	result.y = lambda * vector.y;
	result.z = lambda * vector.z;
	return (result);
}

t_vect_d2	lambda_product_d2(double lambda, t_vect_d2 vector)
{
	t_vect_d2	result;

	result.x = lambda * vector.x;
	result.y = lambda * vector.y;
	return (result);
}
