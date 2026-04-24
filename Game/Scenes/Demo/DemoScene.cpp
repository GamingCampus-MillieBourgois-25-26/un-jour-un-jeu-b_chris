#include "demoscene.h"
#include <random>
#include "assetsmodule.h"
#include "spriterenderer.h"
#include "squarecollider.h"
#include "textrenderer.h"
#include "texture.h"
#include "windowmodule.h"

#include "demo/tilecounter.h"
#include "demo/tilespawner.h"

//demo::demoscene::demoscene(): scene("demoscene") 
//{
//	gameobject* background = creategameobject("background");
//
//	gameobject* player = creategameobject("player");
//	player->createcomponent<bullethell::player>(300.f, 550.f);
//
//	gameobject* enemy = creategameobject("enemy");
//	enemy->createcomponent<bullethell::enemy>(300.f, 350.f);
//
//	assetsmodule* assets_module = engine::getinstance()->getmodulemanager()->getmodule<assetsmodule>();
//	texture* textureplayer = assets_module->loadasset<texture>("playership.png");
//	texture* texturebackground = assets_module->loadasset<texture>("wallpapervoxel.jpg");
//
//demo::demoscene::demoscene(): scene("demoscene")
//{
//    assetsmodule* assets_module = engine::getinstance()->getmodulemanager()->getmodule<assetsmodule>();
//    texture* logo_texture = assets_module->loadasset<texture>("engine/sfml_logo.png");
//
//	player->createcomponent<spriterenderer>(textureplayer);
//	background->createcomponent<spriterenderer>(texturebackground);
//}

//gameobject* demo::demoscene::createdummygameobject(const std::string& _name, const float _position, const sf::color _color) {
//    gameobject* game_object = creategameobject(_name);
//    game_object->setposition(maths::vector2f(_position, _position));
//
//    squarecollider* square_collider = game_object->createcomponent<squarecollider>();
//    square_collider->setwidth(20.f);
//    square_collider->setheight(20.f);
//
//    rectangleshaperenderer* shape_renderer = game_object->createcomponent<rectangleshaperenderer>();
//    shape_renderer->setcolor(_color);
//    shape_renderer->setsize(maths::vector2f(200.f, 200.f));
//    gameobject* const& logo = creategameobject("sfml logo");
//    logo->createcomponent<spriterenderer>(logo_texture, false);
//
//    return game_object;
//}

//void demo::demoscene::shouldcreatebullet()
//{
//	if (bulletcount <= 100)
//	{
//		logger::log(eloglevel::debug, "shoot avec succes");
//
//		gameobject* bullet = creategameobject("bullet");
//		squarecollider* square_collider = bullet->createcomponent<squarecollider>();
//		square_collider->setwidth(40.f);
//		square_collider->setheight(20.f);
//
//		rectangleshaperenderer* shape_renderer = bullet->createcomponent<rectangleshaperenderer>();
//		shape_renderer->setcolor(sf::color::green);
//		shape_renderer->setsize(maths::vector2f(40.f, 20.f));
//
//		bullet->createcomponent<bullethell::bullet>(100.f, 400.f, 400.f);
//	}
//}
//    gameobject* tile_spawner = creategameobject("tilespawner");
//    tile_spawner->createcomponent<tilespawner>();
//    tile_spawner->createcomponent<tilecounter>();
//    tile_spawner->setposition({200, 0});
//}
