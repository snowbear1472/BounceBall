#pragma once

#include <string>

#include "Entities/Player.hh"


namespace BounceBall
{
	namespace Entity
	{
		class Ball : public Player
		{
		public:
			Ball( ) = default;

		public:
			void handle_event( sf::Event e ) override;
			void handle_input( ) override;
			void update( sf::Time delta_time ) override;
			void fixed_update( sf::Time delta_time ) override;
			void render( StateBase*& handle ) override;

		public:
			directions get_directions( ) const override;

		public:
			void move( directions direction ) override;
			void jump( );
			void reset( ) override;

		public:
			void init( );

		public:
			void parse( const string_lines* lines ) override;
			void parse( const csv_map* csv ) override;

		public:
			float jump_limit_;
			float jump_save;

			sf::Vector2f velocity_;

			float radius_;

		private:
			csv_map* default_ball_;
		};
	}
}