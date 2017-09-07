#include "Util\FileUtil.hh"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>


namespace BounceBall
{
	std::string get_file_content( const std::string& path, bool throws )
	{
		std::ifstream stream( path );

		if ( stream.is_open( ) )
		{
			std::ostringstream str;
			str << stream.rdbuf( );

			return str.str( );
		}
		else
		{
			std::string e = "Unable to open file: " + path + " !";

			if ( throws )
				throw std::runtime_error( e );
			else
				std::cerr << e << std::endl;
		}
	}
}