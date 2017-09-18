#pragma once

#include <map>

#include "Util/Utility.hh"


namespace BounceBall
{
	namespace Manager
	{
		struct GameFile
		{
			enum class Type
			{
				None,
				Object,
				Entity,
				Map
			};

			std::string path;
			Type type;
			csv_map csv;
		};

		class GameFileManager
		{
		private:
			GameFileManager( ) = default;

		public:
			static GameFileManager& get( );

		public:
			GameFile& get( path& file );
			void add( path& file );

		public:
			std::vector<GameFile> res;
		};
	}
}