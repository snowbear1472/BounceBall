#pragma once

#include <SFML/Graphics.hpp>

#include <stack>
#include <string>
#include <cctype>


// operator for sf::Vector2f
namespace BounceBall
{
	bool operator==( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return ( lhs.x == rhs.x && lhs.y == rhs.y );
	}
	bool operator!=( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return !( lhs == rhs );
	}
	bool operator>( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return ( lhs.x > rhs.x && lhs.y > rhs.y );
	}
	bool operator<( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return !( lhs > rhs );
	}
	bool operator<=( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return ( lhs > rhs || lhs == rhs );
	}
	bool operator>=( const sf::Vector2f& lhs, const sf::Vector2f& rhs )
	{
		return ( lhs < rhs || lhs == rhs );
	}
}


// version for mapfile class
namespace BounceBall
{
	class Version final
	{
	public:
		Version( ) = default;
		Version( const std::size_t& major, const std::size_t& minor, const std::size_t& revision, const std::size_t& build )
			: major_( major )
			, minor_( minor )
			, revision_( revision )
			, build_( build )
		{}

	public:
		void parse( const std::string& ver )
		{
			std::stack<std::size_t> vers;
			std::string buffer = "";


			for ( int i = 0; i < ver.length( ); i++ )
			{
				auto& c = ver[i];

				if ( c == '.' )
					continue;
				else if ( std::isdigit( c ) )
				{
					do
						buffer += ver[i++];
					while ( std::isdigit( ver[i] ) );

					i--;

					vers.push( std::stoi( buffer ) );
					buffer = "";
				}
			}


			if ( vers.size == 4 )
			{
				build_ = vers.top( );
				vers.pop( );

				revision_ = vers.top( );
				vers.pop( );

				minor_ = vers.top( );
				vers.pop( );

				major_ = vers.top( );
				vers.pop( );
			}
			else
				std::runtime_error( "can't parse version!" );
		}

	public:
		std::size_t major_;
		std::size_t minor_;
		std::size_t revision_;
		std::size_t build_;
	};
}