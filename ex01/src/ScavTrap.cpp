/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:42:08 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/17 18:44:05 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Scav Doe")
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	_health = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parametrized ScavTrap constructor called" << std::endl;
	_health = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_name = other._name;
	_health = other._health;
	_energy = other._energy;
	_damage = other._damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_health = other._health;
	_energy = other._energy;
	_damage = other._damage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_health == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " tried to attack but they are dead!" << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " tried to attack but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _damage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	long long tempHP = static_cast<long long>(_health) - amount;
	if (tempHP < 0)
		_health = 0;
	else
		_health -= amount;
	std::cout << "ScavTrap " << _name << " takes " << amount
		<< " damage causing them to drop to " << _health << " health!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_health == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " tried to repair but they are dead!" << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " tried to repair but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	long long tempHP = static_cast<long long>(_health) + amount;
	std::cout << "ScavTrap " << _name << " is repaired by " << amount << "!";
	if (tempHP > 100)
	{
		_health = 100;
		std::cout << " Too bad extra repair is wasted...";
	}
	else
		_health += amount;
	std::cout << " They now have " << _health << " health!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_health == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " tried to go into Gate keeper mode but they are dead!" << std::endl;
		return ;
	}
	if (_energy == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " tried to go into Gate keeper mode but they are out of energy!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "ScavTrap " << _name << " is in Gate keeper mode!" << std::endl;
}
