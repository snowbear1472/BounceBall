#pragma once

#include <vector>
#include <string>
#include <map>

#include "Object.hh"
#include "Entity.hh"
#include "Util/Utility.hh"


namespace BounceBall
{
	class MapFile final
	{
	public:
		enum class ErrorType
		{
			NOT_FOUND__FILE,
			UNKWON__FILE,

			NOT_FOUND__SCRIPT,
			UNKWON__SCRIPT,

			NOT_FOUND__META_DATA,
			UNKWON__META_DATA,

			NOT_FOUND__ID,
			UNKWON__ID,
		};

		#define msg(type, str) std::make_pair(type, str)
		std::map<ErrorType, std::string> error_messages_
		{
			msg( ErrorType::NOT_FOUND__FILE, "not_found!: file not found." ),
			msg( ErrorType::UNKWON__FILE, "unkwon!: unkwon file." ),

			msg( ErrorType::NOT_FOUND__SCRIPT, "not_found!: script not found." ),
			msg( ErrorType::UNKWON__SCRIPT, "unkwon!: unkwon script." ),

			msg( ErrorType::NOT_FOUND__META_DATA, "not_found!: meta_data not found." ),
			msg( ErrorType::UNKWON__META_DATA, "unkwon!: unkwon meta_data." ),

			msg( ErrorType::NOT_FOUND__ID, "not_found!: id not found." ),
			msg( ErrorType::UNKWON__ID, "unkwon!: unkwon id." )
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
		~MapFile( );

	public:
		void init( );
		void reset( );

	public:
		void parse_from_file( const std::string& path );
		void parse_from_string( const string_lines lines );

	private:
		void parse_ver_1_0( const csv_map* csv );

	private:
		std::string& replace_tokens( std::string& line );

	public:
		sf::Vector2f map_size_;

	public:
		std::map<sf::Vector2f, Object*> objects_;
		std::map<sf::Vector2f, Entity*> entities_;

	private:
		csv_map* default_map_;
	};
}