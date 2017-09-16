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

	std::string Version::to_string( ) const
	{
		return std::to_string( major_ ) + '.' + std::to_string( minor_ ) + '.'
			+ std::to_string( revision_ ) + '.' + std::to_string( build_ );
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


	csv_map parse_csv( const string_lines* file )
	{
		csv_map buffer;
		std::string sbuffer = "";


		for ( auto& i : *file )
		{
			for ( int j = 0; j < i.size( ); j++ )
			{
				auto& c = i[j];

				if ( std::isalpha( c ) )
				{
					if ( sbuffer.empty( ) )
					{
						sbuffer = read_buffer( i, j );
					}
					else
					{
						buffer[sbuffer].push_back( read_buffer( i, j ) );
					}
				}
				else if ( c == '(' )
				{
					if ( sbuffer.empty( ) )
					{
						sbuffer = read_buffer_paren( i, j );
					}
					else
					{
						buffer[sbuffer].push_back( read_buffer_paren( i, j ) );
					}
				}
				else if ( c == '"' )
				{
					if ( sbuffer.empty( ) )
					{
						sbuffer = read_buffer( i, j, '"' );
					}
					else
					{
						buffer[sbuffer].push_back( read_buffer( i, j, '"' ) );
					}
				}
			}

			sbuffer = "";
		}


		return buffer;
	}
}


namespace BounceBall
{
	bool file_exist( path& file )
	{
		std::ifstream infile( file );
		return infile.good( );
	}
	std::string get_extension( path& file )
	{
		std::string buffer = "";


		for ( int i = file.length( ) - 1; i <= 0; i++ )
		{
			if ( file[i] == '.' )
			{
				return buffer;
			}
			else
			{
				buffer += file[i];
			}
		}


		return "";
	}
	string_lines read_file( path& file )
	{
		string_lines buffer;
		std::string line = "";

		std::ifstream stream( file );


		if ( stream.is_open( ) )
		{
			while ( std::getline( stream, line ) )
				buffer.push_back( line );

			line = "";
		}


		return buffer;
	}
}


namespace BounceBall
{
	sf::Color parse_color( const std::string& line )
	{
		sf::Color buffer;
		std::vector<std::string> vbuffer;
		std::string sbuffer = "";


		for ( auto& i : line )
		{
			if ( i == '(' || i == ')' )
			{
				continue;
			}

			if ( i == ',' || i == ' ' )
			{
				if ( sbuffer.empty( ) )
				{
					continue;
				}
				else
				{
					vbuffer.push_back( sbuffer );
					sbuffer = "";
				}
			}
			else
			{
				sbuffer += i;
			}
		}

		buffer.r = std::stoi( vbuffer.at( 0 ) );
		buffer.g = std::stoi( vbuffer.at( 1 ) );
		buffer.b = std::stoi( vbuffer.at( 2 ) );
		buffer.a = std::stoi( vbuffer.at( 3 ) );


		return buffer;
	}
}