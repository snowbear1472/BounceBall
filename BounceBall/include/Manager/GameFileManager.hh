#pragma once

#include "Util/Utility.hh"
#include "Entity.hh"
#include "Object.hh"


namespace BounceBall
{
	namespace Manager
	{
		class GameFileManager final
		{
		private:
			GameFileManager( ) = default;
		private:
			~GameFileManager( );

		public:
			static GameFileManager& get( );
		};
	}
}