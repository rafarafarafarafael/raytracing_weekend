#include <iostream>
#include <cstdint>

#include "vec3.h"
#include "color.h"

int main()
{
	// Image
	const int imageWidth = 256;
	const int imageHeight = 256;
	color pixel_color;
	int i, j;

	// Render
	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	for (j = 0; j < imageHeight; j++){
		std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
		for(i = 0; i < imageWidth; i ++){
			pixel_color = color(double(i)/(imageWidth - 1), double(j)/(imageHeight - 1), 0);
			write_color(std::cout, pixel_color);
		}
	}

	std::clog << "\rDone.                                   \n";

	return 0;
}