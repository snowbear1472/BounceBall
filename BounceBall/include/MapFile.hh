#pragma once

#include <vector>
#include <string>
#include <map>

#include "Object.hh"
#include "Entity.hh"
#include "Util/Utility.hh"


namespace BounceBall
{
	class MapFile final : public ParseBase
	{
	public:
		enum class TokenType
		{
			map_name,
			size,
			display_size,
			background_color,
			background_texture,

			add
		};

		#define map( type ) std::make_pair( #type, type )
		std::map<std::string, TokenType> tokens_map
		{
			map( TokenType::map_name ),
			map( TokenType::size ),
			map( TokenType::display_size ),
			map( TokenType::background_color ),
			map( TokenType::background_texture )
		};
		#undef map

	public:
		enum class EnvironValueType
		{
			TYPE__DATA
		};

		#define map( type, str ) std::make_pair( type, str )
		std::map<EnvironValueType, std::string> environ_values_map
		{
			map( EnvironValueType::TYPE__DATA, "bounceball:map" )
		};
		#undef msg

	public:
		enum class ErrorType
		{
			NOT_FOUND__SCRIPT,
			UNKWON__SCRIPT,

			NOT_FOUND__ID,
			UNKWON__ID,

			FATAL_ERROR
		};

		#define msg(type, str) std::make_pair(type, str)
		std::map<ErrorType, std::string> error_messages_map
		{
			msg( ErrorType::NOT_FOUND__SCRIPT, "not_found!: script not found." ),
			msg( ErrorType::UNKWON__SCRIPT, "unkwon!: unkwon script." ),

			msg( ErrorType::NOT_FOUND__ID, "not_found!: id not found." ),
			msg( ErrorType::UNKWON__ID, "unkwon!: unkwon id." ),

			msg( ErrorType::FATAL_ERROR, "fatal_error!" )
		};
		#undef msg

	public:
		enum class IDType
		{

		};

		#define token(str, type) std::make_pair(str, type)
		std::map<std::string, IDType> id_tokens_map
		{

		};
		#undef token

	public:
		MapFile( ) = default;
	public:
		~MapFile( );

	public:
		const Version recommend_parse_version( ) const override;
		std::string& replace_tokens( std::string& line );

	public:
		void parse( path& file ) override;
		void parse( const string_lines* lines ) override;
		void parse( const csv_map* csv ) override;

	private:
		void parse_ver_1_0_0_0( const csv_map* csv );

	public:
		void init( );
		void reset( );

	public:
		std::string map_name_;
		sf::Vector2f map_size_;
		sf::Vector2f display_size_;
		sf::Color background_color_;
		sf::Texture background_texture_;
		sf::IntRect background_texture_rect_;

	public:
		std::vector<std::shared_ptr<Object>> objects_;
		std::vector<std::shared_ptr<Entity>> entities_;
	};


	using MapFilePtr = std::shared_ptr<MapFile>;

	MapFilePtr make_mapfile( );
}