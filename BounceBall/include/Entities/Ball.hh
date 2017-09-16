#pragma once

#include <string>

#include "Entities/Player.hh"


namespace BounceBall
{
	namespace Entities
	{
		class Ball : public Player
		{
		public:
			enum class TokenType
			{
				radius
			};
			#define map( type ) std::make_pair( #type, type )
			std::map<std::string, TokenType> tokens_map
			{
				map( TokenType::radius )
			};
			#undef map

		public:
			enum class EnvironValueType
			{

			};

			#define map( str, type ) std::make_pair( str, type )
			std::map<std::string, EnvironValueType> environ_values
			{

			};
			#undef map

		public:
			enum class StateType
			{
				Jumping,
				Stand
			};

		public:
			enum class JumpType
			{
				Rising,
				Falling
			};

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
			//virtual moves get_directions( ) const override;

		public:
			virtual void move( const moves& direction ) override;
			void jump( );

		public:
			float jump_;
			float radius_;

		public:
			StateType state_;
			JumpType jump_state_;
		};


		using BallPtr = std::shared_ptr<Ball>;

		BallPtr make_ball( );
	}
}