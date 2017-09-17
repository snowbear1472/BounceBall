#pragma once

#include "Entity.hh"


namespace BounceBall
{
	namespace Entities
	{
		class Player : public Entity
		{
		public:
			enum class TokenType
			{
				velocity,
				key_type
			};
			#define map( type ) std::make_pair( #type, type )
			std::map<std::string, TokenType> tokens_map
			{
				map( TokenType::velocity ),
				map( TokenType::key_type )
			};
			#undef map

		public:
			enum class EnvironValueType
			{

			};

			#define map( str, type ) std::make_pair( str, type )
			std::map<std::string, EnvironValueType> environ_values_map
			{

			};
			#undef map

		public:
			enum class MoveKeyType
			{
				TYPE__1,
				TYPE__2
			};

			#define key( str, type ) std::make_pair( str, type )
			std::map<std::string, MoveKeyType> key_map
			{
				key( "type1", MoveKeyType::TYPE__1 ),
				key( "type2", MoveKeyType::TYPE__2 )
			};
			#undef key

		public:
			enum class MoveDirectionType
			{
				up,
				down,

				left,
				right
			};

			#define map( type, velocity ) std::make_pair( type, velocity )
			std::map<MoveDirectionType, float> move_map
			{
				map( MoveDirectionType::up, 10.0f ),
				map( MoveDirectionType::down, -10.0f ),

				map( MoveDirectionType::left, -10.0f ),
				map( MoveDirectionType::right, 10.0f ),
			};
			#undef map

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