#pragma once

#include "EntityBase.hh"


namespace BounceBall
{
	namespace Entity
	{
		class Player : public EntityBase
		{
		public:
			enum class MoveKeyType
			{
				wasd,
				updownleftright
			};
			enum class MoveDirectionType
			{
				up,
				down,

				left,
				right
			};
			using directions = std::vector<MoveDirectionType>;

		public:
			Player( ) = default;

		public:
			virtual void handle_event( sf::Event e ) override;
			virtual void handle_input( ) override;
			virtual void update( sf::Time delta_time ) override;
			virtual void fixed_update( sf::Time delta_time ) override;
			virtual void render( StateBase*& handle ) override;

		public:
			virtual directions get_directions( ) const;

		public:
			virtual void move( directions direction );
			virtual void reset( );

		public:
			void init( ) override;

		public:
			virtual void parse( const string_lines* lines ) override;
			virtual void parse( const csv_map* csv ) override;

		public:
			Player* default_player_;
			MoveKeyType key_type_;
		};
	}
}