#pragma once

#include "Util/Utility.hh"


namespace BounceBall
{
	namespace Manager
	{
		class GameFileManager final
		{
		public:
			GameFileManager( ) = default;

		public:
			string_lines get( const std::string& path );
			csv_map get( const string_lines* lines );
		};
	}
}