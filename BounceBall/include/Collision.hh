#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>


namespace BounceBall
{
	class Collision
	{
	public:
		enum class CollisionType
		{
			up,
			down,
			left,
			right,
			none
		};

	public:
		Collision( sf::RectangleShape& shape );

	public:
		sf::Vector2f get_real_pos( ) const;
		sf::Vector2f get_real_end_pos( ) const;

	public:
		void update( const Collision& col );
		bool isCollision( const Collision& col ) const;

	public:
		std::shared_ptr<sf::RectangleShape> shape_;

	public:
		std::map<CollisionType, bool> collisions_;
	};
}