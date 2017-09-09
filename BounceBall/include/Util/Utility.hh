#pragma once

#include <SFML/Graphics.hpp>


// operator for sf::Vector2f
namespace BounceBall
{
	bool operator==( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return ( lhs.x == rhs.x && lhs.y == rhs.y );
	}
	bool operator!=( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return !( lhs == rhs );
	}
	bool operator>( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return ( lhs.x > rhs.x && lhs.y > rhs.y );
	}
	bool operator<( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return !( lhs > rhs );
	}
	bool operator<=( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return ( lhs > rhs || lhs == rhs );
	}
	bool operator>=( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return ( lhs < rhs || lhs == rhs );
	}
}