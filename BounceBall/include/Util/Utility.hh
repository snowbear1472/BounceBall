#pragma once

#include <SFML/Graphics.hpp>

#include <stack>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <map>
#include <memory>


// for all class
namespace BounceBall
{
	using path = const std::string;
}

// operator for sf::Vector2f
namespace BounceBall
{
	bool operator==( const sf::Vector2f& lhs, const sf::Vector2f& rhs );
	bool operator!=( const sf::Vector2f& lhs, const sf::Vector2f& rhs );
	bool operator>( const sf::Vector2f& lhs, const sf::Vector2f& rhs );
	bool operator<( const sf::Vector2f& lhs, const sf::Vector2f& rhs );
	bool operator<=( const sf::Vector2f& lhs, const sf::Vector2f& rhs );
	bool operator>=( const sf::Vector2f& lhs, const sf::Vector2f& rhs );
}


// version for mapfile class
namespace BounceBall
{
	class Version final
	{
	public:
		Version( ) = default;
		Version( const std::size_t& major, const std::size_t& minor, const std::size_t& revision, const std::size_t& build );

	public:
		void parse( const std::string& ver );

	public:
		std::string to_string( ) const;

	public:
		std::size_t major_;
		std::size_t minor_;
		std::size_t revision_;
		std::size_t build_;

	public:
		bool operator==( const Version& rhs );
		bool operator!=( const Version& rhs );
	};
}


// vector2f parser for mapfile class
namespace BounceBall
{
	sf::Vector2f parse_vector2f( const std::string& str );
	bool is_vector2f_str( const std::string& str );

	sf::Vector2i to_vector2i( const sf::Vector2f vec );
}


// csv parser for mapfile class and others
namespace BounceBall
{
	using csv_map = std::vector<std::vector<std::string>>;
	using string_lines = std::vector<std::string>;


	bool when( char c );
	bool when( char c, char con );
	bool when_paren( char c );

	std::string read_buffer( const std::string& line, int& index );
	std::string read_buffer( const std::string& line, int& index, char con );
	std::string read_buffer_paren( const std::string& line, int& index );

	csv_map parse_csv( const string_lines* file, std::size_t& index );
	const std::string* csv_find( const csv_map* csv, const std::string& name );
}


namespace BounceBall
{
	string_lines read_file( const std::string& path );
}