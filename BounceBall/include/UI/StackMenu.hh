#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Widget.hh"
#include "NonCopyable.hh"


namespace BounceBall
{
	namespace UI
	{
		class StackMenu : public NonCopyable
		{
		public:
			StackMenu( const sf::RenderWindow& handle );
			StackMenu( const sf::Vector2f& pos );
			StackMenu( StackMenu&& other );

			~StackMenu( ) = default;

		public:
			StackMenu& operator=( StackMenu&& other );

		public:
			void add_widget( std::unique_ptr<Widget> widget );

			void handle_event( sf::Event e, const sf::RenderWindow& handle );
			void render( sf::RenderTarget& handle );

		private:
			void init_widget( Widget& widget );

		private:
			std::vector<std::unique_ptr<Widget>> widgets_;
			sf::RectangleShape background_;

			sf::Vector2f base_pos_;
			sf::Vector2f base_size_;
		};
	}
}