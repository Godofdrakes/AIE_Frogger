#ifndef _TEXTURESTRINGS_H_
#define _TEXTURESTRINGS_H_

#include <list>
#include <string>
#include <sstream>

class TextureStrings {
private:
protected:
public:
	// Lists that will be populated with each kind of texture
	std::list<std::string> road;
	std::list<std::string> terrain;
	std::list<std::string> water;

	TextureStrings(void);
	~TextureStrings(void);

};

#endif
