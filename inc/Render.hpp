#ifndef _RENDER_H_
#define _RENDER_H_

#include <SFML/Graphics.hpp>

class Render
{
public:
  Render(unsigned int width, unsigned int height);
  virtual ~Render();

  void	run();

private:
  void	loadNoise(sf::Image &image);
  float scaleNumber(float nb, float flb, float fhb,
		    float lb, float hb) const { return (((hb - lb) * (nb - flb)) / (fhb - flb) + lb); }

private:
  sf::RenderWindow	_window;
  bool			_refresh;
  float			_val;
};

#endif /* _RENDER_H_ */
