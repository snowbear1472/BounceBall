#pragma once

#include <cctype>

#include "StateBase.hh"
#include "Animation.hh"
#include "Collision.hh"
#include "Util/Utility.hh"
#include "Manager/ResourceHolder.hh"
#include "ParseBase.hh"


namespace BounceBall
{
	class Entity : public ParseBase
	{
	public:
		enum class TokenType
		{
			entity_name,
			size,
			color,
			texture,
			animation,
			frame
		};
		#define map( type ) std::make_pair( #type, type )
		std::map<std::string, TokenType> tokens_map
		{
			map( TokenType::entity_name ),
			map( TokenType::size ),
			map( TokenType::color ),
			map( TokenType::texture ),
			map( TokenType::animation ),
			map( TokenType::frame )
		};
		#undef map

	public:
		enum class EnvironValueType
		{
			TYPE__DATA
		};

		#define map( type, str ) std::make_pair( type, str )
		std::map<EnvironValueType, std::string> environ_values
		{
			map(EnvironValueType::TYPE__DATA, "bounceball:entity" )
		};
		#undef map

	public:
		enum class ErrorType
		{
			NOT_FOUND__SCRIPT,
			UNKWON__SCRIPT,
		};

		#define msg( type, str ) std::make_pair( type, str )
		std::map<ErrorType, std::string> error_messages
		{
			msg( ErrorType::NOT_FOUND__SCRIPT, "not_found!: script not found." ),
			msg( ErrorType::UNKWON__SCRIPT, "unkwon!: unkwon script." ),
		};
		#undef msg

	public:
		Entity( ) = default;

	public:
		virtual void handle_event( sf::Event e ) = 0;
		virtual void handle_input( ) = 0;
		virtual void update( sf::Time delta_time ) = 0;
		virtual void fixed_update( sf::Time delta_time ) = 0;
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
		std::string entity_name_;

	public:
		sf::RectangleShape shape_;
		sf::Texture texture_;

	public:
		std::shared_ptr<Animation> animation_;
		std::shared_ptr<Collision> collision_;
	};
}