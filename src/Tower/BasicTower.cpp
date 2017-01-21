//
// Created by thomas on 21/01/17.
//

#include <MagickAttack.hpp>
#include <Projectile.hpp>
#include <ATower.hpp>
#include <BasicTower.hpp>
#include <Display/TextureManager.hpp>

BasicTower::BasicTower(float x, float y, unsigned hp, int mp, int range, float atkSpeed, MagickAttack * magic, Projectile * projectile, std::list<Monster*>& monsters) :
    ATower(x, y, hp, mp, range, atkSpeed, magic, projectile, monsters)
{
    sf::Texture const& text = TextureManager::get(TextureManager::TOWER);
    this->addSprites(text, sf::IntRect(0, 0, text.getSize().x, text.getSize().y), 1);
}

BasicTower::~BasicTower() {

}

void BasicTower::Speak() const {
    std::cout << "PWET" << std::endl;
}
