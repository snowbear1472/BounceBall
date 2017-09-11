#pragma once

#include "Util/Utility.hh"
#include "EntityBase.hh"
#include "Object.hh"


namespace BounceBall
{
	namespace Manager
	{
		class GameFileManager final
		{
		public:
			enum class Type
			{
				entity,
				object
			};

		public:
			static GameFileManager& get( );

		private:
			GameFileManager( );

		public:
			csv_map get( const std::string& name, const Type& type );
			EntityBase* get_entity( const std::string& name );
			Object* get_object( const std::string& name );

		private:
			path get_fullpath( const std::string& name, const Type& type );

		public:
			std::string dir_entity_;
			std::string dir_object_;
			std::string extension_;
		};
	}
}