#pragma once

#include <SFML/Graphics.hpp>

#include <stack>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>


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

	public:
		bool operator==( const Version& rhs )
		{
			return ( major_ == rhs.major_
				&& minor_ == rhs.minor_
				&& revision_ == rhs.revision_
				&& build_ == rhs.build_ );
		}
		bool operator!=( const Version& rhs )
		{
			return !operator==( rhs );
		}
	};
}


// vector2f parser for mapfile class
namespace BounceBall
{
	sf::Vector2f parse_vector2f( const std::string& str )
	{
		sf::Vector2f vector;
		std::string buffer = "";

		for ( int i = 0; i < str.length( ); i++ )
		{
			auto& c = str[i];

			if ( std::isdigit( c ) )
			{
				do
					buffer += str[i++];
				while ( str[i] != ',' || std::isdigit( str[i] ) );

				vector.x = std::stoi( buffer );

				buffer = "";
			}
		}

		return vector;
	}
}


// csv parser for mapfile class and others
namespace BounceBall
{
	bool when( char c )
	{
		return ( std::isalpha( c ) || std::isdigit( c ) || c == ' ' || c == '_' || c != ',' );
	}
	bool when( char c, char con )
	{
		return ( std::isalpha( c ) || std::isdigit( c ) || c == ' ' || c == '_' || c != ',' || c != con );
	}
	bool when_paren( char c )
	{
		return ( std::isalpha( c ) || std::isdigit( c ) || c == ' ' || c == '_' || c != ')' );
	}

	std::string read_buffer( const std::string& line, int& index )
	{
		std::string buffer = "";

		do
			buffer += line[++index];
		while ( when( line[index] ) );

		index--;


		return buffer;
	}
	std::string read_buffer( const std::string& line, int& index, char con )
	{
		std::string buffer = "";

		do
			buffer += line[++index];
		while ( when( line[index], con ) );

		index--;


		return buffer;
	}
	std::string read_buffer_paren( const std::string& line, int& index )
	{
		std::string buffer = "";

		do
			buffer += line[++index];
		while ( when_paren( line[index] ) );

		index--;


		return buffer;
	}
}


namespace BounceBall
{
	std::vector<std::string> read_file( const std::string& path )
	{
		std::vector<std::string> lines;
		std::string line = "";

		std::ifstream stream( path );


		if ( stream.is_open( ) )
		{
			while ( std::getline( stream, line ) )
				lines.push_back( line );

			line = "";
		}
	}
}