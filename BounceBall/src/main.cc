#include <iostream>
#include "Util/Utility.hh"
#include "Entities/Ball.hh"


int main( )
{
	std::size_t index = 0;

	auto& file = BounceBall::read_file( "res/entity/default_ball.csv" );
	auto& csv = BounceBall::parse_csv( &file, index );

	for ( auto& i : csv )
	{
		std::cout << i.first << ": " << i.second << std::endl;
	}

	BounceBall::Entity::Ball ball;
	ball.parse( csv );

	std::cin.get( );


	return 0;
}