#pragma once

#include <functional>

#include "Widget.hh"


namespace BounceBall
{
	namespace UI
	{
		class Textbox : public Widget
		{
		public:
			Textbox( const std::string& str );

		public:
			void set_label( const std::string& str );
			void set_texture( const sf::Texture& texture );

			void handle_event( sf::Event e, const sf::RenderWindow& handle ) override;
			void render( sf::RenderTarget& handle ) override;
			void set_position( const sf::Vector2f& pos ) override;
			sf::Vector2f get_size( ) const override;

		private:
			void handle_click( sf::Event e, const sf::RenderWindow& handle );
			void handle_text_changed( sf::Event e );

		private:
			sf::Vector2f pos_;
			Rectangle rect_;
			Text text_;
			Text label_;
			std::string mod_str_;

			bool enable = false;
		};
	}
}