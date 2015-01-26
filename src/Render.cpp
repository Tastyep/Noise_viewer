#include <iostream>
#include "Render.hpp"
extern "C" {
#include "Perlin.h"
#include "TurbulenceNoise.h"
#include "FBM_Noise.h"
#include "RMF_Noise.h"
}

Render::Render(unsigned int width, unsigned int height) :
  _window(sf::VideoMode(width, height), "Noise Renderer"),
  _refresh(true)
{
  _val = 0;
}

Render::~Render()
{
}

void	Render::loadNoise(sf::Image &image)
{
  sf::Vector2u	size = image.getSize();
  float		value;
  sf::Color	c;

  for (unsigned int y = 0; y < size.y; ++y)
    {
      for (unsigned int x = 0; x < size.x; ++x)
	{
	  value = ridged_mf2(2, 2.5, 0.6, 0.0025, 1.0, x, y);
	  if (value >= 0 && value <= 1)
	    c = sf::Color(20 + 235 * value,
	  		  20 + 235 * value,
	  		  65 + 190 * value);
	  else
	    c = sf::Color(0,0,0);
	  image.setPixel(x, y, c);
	}
    }
}

void	Render::run()
{
  sf::Event		event;
  sf::Image		image;
  sf::Texture		texture;
  sf::Sprite		sprite;
  sf::Vector2u		size = _window.getSize();

  image.create(size.x, size.y, sf::Color::Black);
  texture.create(size.x, size.y);
  while (_window.isOpen())
    {
      _window.clear();
      while (_window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    _window.close();
	  if (_refresh ||
	      event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
	    {
	      loadNoise(image);
	      texture.update(image);
	      sprite.setTexture(texture);
	      _refresh = false;
	    }
	  else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
	    {
	      _val += 0.1;
	      _refresh = true;
	    }
	  else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
	    {
	      _val -= 0.1;
	      _refresh = true;
	    }
	}
      _window.draw(sprite);
      _window.display();
    }
}
