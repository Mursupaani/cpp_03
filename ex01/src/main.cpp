/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:48:09 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/17 18:07:44 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1 {"Sir Clappington"};
	ClapTrap clap2;
	clap1.attack("Pena");
	clap2.attack("Sir Clappington");
	clap1.takeDamage(5);
	clap2.takeDamage(15);
	clap1.beRepaired(2);
	clap2.beRepaired(15);
	return (EXIT_SUCCESS);
}
