#include <iostream>

#include "Util/Utility.hh"
#include "Entities/Ball.hh"
#include "Object.hh"
#include "Manager/GameFileManager.hh"


int main( )
{
	auto obj = BounceBall::Manager::GameFileManager::get( ).get_entity( "default_ball" );


	return 0;
}