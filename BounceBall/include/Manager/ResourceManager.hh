#pragma once

#include <string>
#include <map>


namespace BounceBall
{
	namespace Manager
	{
		template <typename Ty_>
		class ResourceManager final
		{
		public:
			ResourceManager( const std::string& folder, const std::string& extension )
				: dir_( "res/" + folder )
				, extension_( extension )
			{}

		public:
			const Ty_& get( const std::string& name )
			{
				if ( !( res_.find( name ) != res_.end( ) ) )
					add( name );

				return res_.at( name );
			}
			void add( const std::string& name )
			{
				Ty_ res;

				if ( res.loadFromFile( get_fullpath( name ) ) )
					res_.insert( std::make_pair( name, res ) );
				else
				{
					Ty_ fail;
					fail.loadFromFile( get_fullpath( "error" ) );

					res_.insert( std::make_pair( name, fail ) );
				}
			}

		public:
			std::string get_fullpath( const std::string& name )
			{
				return dir_ + "/" + name + "." + extension_;
			}

		private:
			const std::string dir_;
			const std::string extension_;

			std::map<std::string, Ty_> res_;
		};
	}
}