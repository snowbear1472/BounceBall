#pragma once

#include <SFML/Graphics.hpp>
#include <memory>


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
		Collision( ) = default;
		Collision( sf::RectangleShape& shape );

	public:
		sf::Vector2f get_real_pos( ) const;
		sf::Vector2f get_real_end_pos( ) const;
		bool is_collision( const Collision& col ) const;

	public:
		void update( const Collision& col );

	public:
		std::shared_ptr<sf::RectangleShape> shape_;

	public:
		std::map<CollisionType, bool> collisions_;
	};
}