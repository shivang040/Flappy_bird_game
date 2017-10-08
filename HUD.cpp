#include"HUD.h"
#include<string>
#include<sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
namespace game
{
    HUD::HUD(GameDataRef data):_data(data)
    {
        _scoreText.setFont(this->_data->assets.GetFont("Flappy Font"));
        _scoreText.setString("0");
        _scoreText.setCharacterSize(128);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width/2,_scoreText.getGlobalBounds().height/2);
        _scoreText.setPosition(this->_data->window.getSize().x/2,this->_data->window.getSize().y/5);
    }

        void HUD::Draw()
        {
            this->_data->window.draw(_scoreText);
        }
        void HUD::UpdateScore(int score)
        {
            _scoreText.setString(patch::to_string(score));
        }
}
