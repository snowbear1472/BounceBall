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
		bool charge = false;


		for ( int i = 0; i < str.length( ); i++ )
		{
			auto& c = str[i];


			if ( std::isdigit( c ) || c == '(' )
			{
				while ( ( std::isdigit( str[i] ) || str[i] == ' ' || str[i] == '(' || str[i] == ')' ) && str[i] != ',' && i + 1 <= str.length( ) )
					buffer += str[i++];

				if ( charge )
				{
					vector.y = std::stof( buffer );
					break;
				}
				else
				{
					vector.x = std::stof( buffer );

					buffer = "";
					charge = true;
				}

			}
		}


		return vector;
	}
	bool is_vector2f_str( const std::string& str )
	{
		if ( *str.begin( ) == '(' && *str.end( ) == ')' )
			return true;
		else
			return false;
	}

	sf::Vector2i to_vector2i( const sf::Vector2f vec )
	{
		return sf::Vector2i( int( vec.x ), int( vec.y ) );
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

		while ( when( line[index] ) && index + 1 <= line.length( ) )
			buffer += line[index++];


		return buffer;
	}
	std::string read_buffer( const std::string& line, int& index, char con )
	{
		std::string buffer = "";

		while ( when( line[index], con ) && index + 1 <= line.length( ) )
			buffer += line[index++];


		return buffer;
	}
	std::string read_buffer_paren( const std::string& line, int& index )
	{
		std::string buffer = "";

		while ( when_paren( line[index] ) && index + 1 <= line.length( ) )
			buffer += line[index++];


		return buffer;
	}


	csv_map parse_csv( const string_lines* file, std::size_t& index )
	{
		csv_map buffer;
		std::vector<std::string> vbuffer;

		auto& lines = *file;


		for ( ; index < lines.size( ); index++ )
		{
			for ( int i = 0; i < lines[index].length( ); i++ )
			{
				auto& line = lines[index];
				auto& c = line[i];


				if ( std::isalpha( c ) || std::isdigit( c ) )
					vbuffer.push_back( read_buffer( line, i ) );
				else if ( c == '(' )
					vbuffer.push_back( read_buffer_paren( line, i ) );
			}
		}


		return buffer;
	}
	const std::string* csv_find( const csv_map* csv, const std::string& name )
	{
		auto& v = *csv;

		for ( int i = 0; i < v.size( ); i++ )
			for ( int j = 0; j < v[i].size( ); j++ )
				if ( v[i][j] == name )
					return &v[i][j];


		return nullptr;
	}
}


namespace BounceBall
{
	string_lines read_file( const std::string& path )
	{
		string_lines buffer;
		std::string line = "";

		std::ifstream stream( path );


		if ( stream.is_open( ) )
		{
			while ( std::getline( stream, line ) )
				buffer.push_back( line );

			line = "";
		}


		return buffer;
	}
}