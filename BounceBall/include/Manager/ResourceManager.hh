#pragma once

#include <string>
#include <map>


namespace BounceBall
{
	namespace Manager
	{
		template <typename Ty_>
		class ResourceManager
		{
		public:
			ResourceManager( const std::string& folder, const std::string& extension );

		public:
			const Ty_& get( const std::string& name )
			{
				if ( res_.find( name ) != res_.end( ) )
				{

				}
			}
			void add( const std::string& name )
			{
				Ty_ res;

				if ( res.loadFromFile( get_fullpath( name ) ) )
					res_[name] = res;
				else
				{
					Ty_ fail;
					fail.loadFromFile( get_fullpath( "error" ) );

					res_[name] = fail;
				}
			}

		private:
			std::string get_fullpath( const std::string& name )
			{
				return dir + "\\" + name + "." + extension_;
			}

		private:
			const std::string& dir_;
			const std::string& extension_;

			std::map<std::string, Ty_> res_;
		};
	}
}