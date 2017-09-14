#pragma once

#include "Entity.hh"


namespace BounceBall
{
	namespace Entity
	{
		class Player : public Entity
		{
		public:
			enum class MoveKeyType
			{
				wasd,
				updownleftright
			};
			using keys = std::vector<MoveKeyType>;

		public:
			enum class MoveDirectionType
			{
				up,
				down,

				left,
				right
			};
			using moves = std::vector<MoveDirectionType>;

		public:
			Player( ) = default;

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
			virtual void reset( );

		public:
			virtual moves get_directions( ) const;

		public:
			virtual void move( const moves& direction );

		public:
			sf::Vector2f velocity_;
			MoveKeyType key_type_;
		};


		using PlayerPtr = std::shared_ptr<Player>;

		PlayerPtr make_player( );
	}
}