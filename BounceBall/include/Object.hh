#pragma once

#include <SFML/Graphics.hpp>

#include "Util/Utility.hh"
#include "Collision.hh"
#include "ParseBase.hh"


namespace BounceBall
{
	class StateBase;

	class Object : public ParseBase
	{
	public:
		enum class TokenType
		{
			object_name,
			size,
			color,
			texture,
		};
		#define map( type ) std::make_pair( #type, type )
		std::map<std::string, TokenType> tokens_map
		{
			map( TokenType::object_name ),
			map( TokenType::size ),
			map( TokenType::color ),
			map( TokenType::texture )
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
			map( EnvironValueType::TYPE__DATA, "bounceball:entity" )
		};
		#undef map

	public:
		enum class ErrorType
		{
			NOT_FOUND__SCRIPT,
			UNKWON__SCRIPT,
		};

		#define msg( type, str ) std::make_pair( type, str )
		std::map<ErrorType, std::string> error_messages_map
		{
			msg( ErrorType::NOT_FOUND__SCRIPT, "not_found!: script not found." ),
			msg( ErrorType::UNKWON__SCRIPT, "unkwon!: unkwon script." ),
		};
		#undef msg

	public:
		Object( ) = default;

	public:
		virtual void update( sf::Time delta_time ) = 0;
		virtual void render( StateBase*& handle ) = 0;

	public:
		virtual std::string& replace_token( std::string& line ) override;

	public:
		virtual void parse( path& file ) override;
		virtual void parse( const string_lines* lines ) override;
		virtual void parse( const csv_map* csv ) override;

	public:
		virtual void init( ) = 0;
		virtual void reset( ) = 0;

	public:
		std::string object_name_;

	public:
		sf::RectangleShape shape_;
		sf::Texture texture_;

	public:
		std::shared_ptr<Collision> collision_;
	};
}