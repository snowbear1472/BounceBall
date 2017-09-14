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
			virtual void handle_event( sf::Event e ) override;
			virtual void handle_input( ) override;
			virtual void update( sf::Time delta_time ) override;
			virtual void fixed_update( sf::Time delta_time ) override;
			virtual void render( StateBase*& handle ) override;

		public:
			virtual const Version recommend_parse_version( ) const override;
			virtual std::string& replace_token( std::string& line ) override;

		public:
			virtual void parse( path& file ) override;
			virtual void parse( const string_lines* lines ) override;
			virtual void parse( const csv_map* csv ) override;

		public:
			virtual void init( ) override;
			virtual void reset( ) override;

		public:
			virtual moves get_directions( ) const override;

		public:
			virtual void move( const moves& direction ) override;
			void jump( );

		public:
			float jump_limit_;
			float jump_save_;
			float radius_;

		private:
			csv_map* default_ball_;
		};
		

		using BallPtr = std::shared_ptr<Ball>;

		BallPtr make_ball( );
	}
}