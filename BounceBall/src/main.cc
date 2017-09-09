#include <iostream>

#include "Game.hh"

//class single
//{
//private:
//	single( );
//
//public:
//	int num;
//
//private:
//	static single* instance_;
//
//public:
//	static single& get( );
//};
//
//
//single::single( )
//{
//	num = 5;
//}
//
//single* single::instance_ = nullptr;
//
//single& single::get( )
//{
//	if ( !instance_ )
//		instance_ = new single;
//
//	return *instance_;
//}


int main( )
{
	BounceBall::Game game;
	game.run( );


	return 0;
}