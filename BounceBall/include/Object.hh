#pragma once

#include <SFML/Graphics.hpp>


namespace BounceBall
{
	class Object
	{
	public:
		Object( ) = default;
		Object( const sf::Vector2f& size, const sf::Vector2f& pos )
			: shape_( size )
		{
			shape_.setPosition( pos );
		}

	public:
		virtual void update( ) = 0;

	public:
		sf::RectangleShape shape_;
		sf::Texture texture_;
	};
}