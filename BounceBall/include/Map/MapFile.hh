#pragma once

#include <vector>
#include <string>
#include <map>

#include "Object.hh"
#include "EntityBase.hh"
#include "Util/Utility.hh"


namespace BounceBall
{
	class MapFile final
	{
	public:
		enum class ErrorType
		{
			META_DATA_NOT_FOUND,
			META_DATA_WRONG,

			WRONG_ID,
		};

		#define msg(type, str) std::make_pair(type, str)
		std::map<ErrorType, std::string> error_messages_
		{
			msg( ErrorType::META_DATA_NOT_FOUND, "can't find meta data from a map file!" ),
			msg( ErrorType::META_DATA_WRONG, "wrong meta data!" ),

			msg( ErrorType::WRONG_ID, "can't find game_id from client or resources!" ),
		};
		#undef msg

	public:
		enum class IDType
		{
			object,
			entity,

			default_ball,
			default_block_dirt,
			default_block_potal,

			resources_object,
			resources_entity
		};

		#define token(str, type) std::make_pair(str, type)
		std::map<std::string, IDType> id_tokens_
		{
			token( "game:entity", IDType::entity ),
			token( "game:object", IDType::object ),

			token( "game:entity:ball", IDType::default_ball ),
			token( "game:object:block:dirt", IDType::default_block_dirt ),
			token( "game:object:block:potal", IDType::default_block_potal ),

			token( "resources:object:\"%path%\"", IDType::resources_object ),
			token( "resources:block:\"%path%\"", IDType::resources_entity )
		};
		#undef token

	public:
		MapFile( ) = default;

	public:
		void parse_from_file( const std::string& path );
		void parse_from_string( const string_lines lines );

	private:
		void parse_ver_1_0( const csv_map& map );

	private:
		std::string& replace_tokens( std::string& line );

	public:
		string_lines file_;

	public:
		Version version_ = { 0,0,0,0 };
		Version map_version_;
		std::string name_ = "";
		std::string developer_ = "";
		std::string details_ = "";

	public:
		sf::Vector2f map_size_;
		std::map<sf::Vector2f, Object> objects_;
		std::map<sf::Vector2f, EntityBase> entities_;
	};
}