#pragma once

#include <SFML/Graphics.hpp>

#include "Manager\ResourceHolder.hh"


namespace BounceBall
{
	namespace UI
	{
		class Widget
		{
		public:
			virtual void handle_event( sf::Event e, const sf::RenderWindow& handle ) = 0;
			virtual void render( sf::RenderTarget& handle ) = 0;
			virtual void set_position( const sf::Vector2f& pos ) = 0;
			virtual sf::Vector2f get_size( ) const = 0;

		protected:
			class Text : public sf::Text
			{
			public:
				Text( );
			};

			class Rectangle : public sf::RectangleShape
			{
			public:
				bool is_rolled_on( const sf::RenderWindow& handle ) const;
				bool is_clicked( sf::Event e, const sf::RenderWindow& handle );
			};
		};
	}
}