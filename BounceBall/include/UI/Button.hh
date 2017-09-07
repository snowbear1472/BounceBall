#pragma once

#include <functional>

#include "Widget.hh"


namespace BounceBall
{
	namespace UI
	{
		class Button : public Widget
		{
		public:
			enum class SizeType
			{
				Small,
				Wide
			};

		public:
			Button( const SizeType& s = SizeType::Wide );

		public:
			void set_func( std::function<void( void )> func );
			void set_text( const std::string& str );
			void set_texture( const sf::Texture& texture );

			void handle_event( sf::Event e, const sf::RenderWindow& handle ) override;
			void render( sf::RenderTarget& handle ) override;
			void set_position( const sf::Vector2f& pos ) override;
			sf::Vector2f get_size( ) const override;

		private:
			void update_text( );

		private:
			sf::Vector2f pos_;
			Rectangle button_;
			Text text_;

			std::function<void( void )> func_ = []( ){};
		};
	}
}