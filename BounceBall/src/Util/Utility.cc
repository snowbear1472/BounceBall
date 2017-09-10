#include "Util/Utility.hh"

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
	Version::Version( const std::size_t& major, const std::size_t& minor, const std::size_t& revision, const std::size_t& build )
		: major_( major )
		, minor_( minor )
		, revision_( revision )
		, build_( build )
	{}

	void Version::parse( const std::string& ver )
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


		if ( vers.size( ) == 4 )
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

	bool Version::operator==( const Version& rhs )
	{
		return ( major_ == rhs.major_
			&& minor_ == rhs.minor_
			&& revision_ == rhs.revision_
			&& build_ == rhs.build_ );
	}
	bool Version::operator!=( const Version& rhs )
	{
		return !operator==( rhs );
	}
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
	using csv_map = std::map<std::string, std::string>;


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


	csv_map parse_csv( const string_lines& lines, std::size_t& index )
	{
		csv_map buffer;
		std::string sbuffer = "";
		bool key = false;


		for ( ; index < lines.size( ); index++ )
		{
			for ( int i = 0; i < lines[index].length( ); i++ )
			{
				auto& line = lines[index];
				auto& c = line[i];


				if ( std::isalpha( c ) ) // name, bounce_ball tutorial
				{
					if ( key )
					{
						buffer[sbuffer] = read_buffer( line, i );

						key = false;
						sbuffer = "";

						continue;
					}
					else
					{
						sbuffer = read_buffer( line, i );

						key = true;
					}
				}

				if ( c == '(' ) // (3, 5), game:object:default_dirt
				{
					if ( key )
					{
						buffer[sbuffer] = read_buffer( line, i );

						key = false;
						sbuffer = "";

						continue;
					}
					else
					{
						sbuffer = read_buffer_paren( line, i );

						key = true;
					}
				}
			}
		}


		return buffer;
	}
}


namespace BounceBall
{
	string_lines read_file( const std::string& path )
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


		return lines;
	}
}