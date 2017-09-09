#pragma once

#include <string>

#include "EntityBase.hh"


namespace BounceBall
{
	namespace Entity
	{
		class Ball : public EntityBase
		{
		public:
			Ball( ) = default;
			Ball( StateBase& base );

		public:
			void handle_event( sf::Event e ) override;
			void handle_input( ) override;
			void update( sf::Time delta_time ) override;
			void fixed_update( sf::Time delta_time ) override;
			void render( sf::RenderTarget& handle ) override;

		public:
			void parse( const std::vector<std::string>& lines ) override;
			void jump( );

		public:
			float jump_limit_ = 30;
			float jump_save;

			sf::Vector2f velocity_;
		};
	}
}