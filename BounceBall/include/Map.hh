#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <stack>
#include <string>
#include <cctype>

#include "EntityBase.hh"
#include "Object.hh"


namespace BounceBall
{
	class Version
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
			std::string temp = "";


			for ( int i = 0; i < ver.length( ); i++ )
			{
				auto& c = ver[i];

				if ( c == '.' )
					continue;
				else if ( std::isdigit( c ) )
				{
					do
						temp += ver[i++];
					while ( std::isdigit( ver[i] ) );

					i--;

					vers.push( std::stoi( temp ) );
					temp = "";
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

	class Map
	{
	public:
		Map( ) = default;

	public:
		void read_from_file( const std::string& path );
		void read_from_string( const std::vector<std::string>& lines );

	public:
		void reset( );

	public:
		Version version_;
		std::string name_;
		std::string developer_;
		std::string details_;
		sf::Vector2f map_size_;

	public:
		std::vector<Object> objects_;
		std::vector<EntityBase> entities_;
	};
}