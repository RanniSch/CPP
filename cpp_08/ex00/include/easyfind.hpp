/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 08:04:47 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/15 09:21:35 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Target not found!");
		}
};

#endif