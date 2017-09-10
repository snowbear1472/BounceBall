#include <iostream>
#include "Util/Utility.hh"


int main( )
{
	std::size_t index = 0;
	auto& csv = BounceBall::parse_csv( BounceBall::read_file( "res/entities/default_ball.csv" ), index );
	for ( auto& i : csv )
	{
		std::cout << i.first << ": " << i.second << std::endl;
	}

	std::cin.get( );


	return 0;
}