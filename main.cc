#include <iostream>
#include <cstdint>

#include "vec3.h"
#include "color.h"
#include "ray.h"

color ray_color(const ray& r){
	return color(0,0,0);
}

int main()
{
	// Variables
	double aspectRatio = 16.0 / 9.0;
	double focalLength = 1.0;
	double viewportHeight = 2.0, viewportWidth;
	point3 cameraCenter = point3(0, 0, 0); 
	int imageWidth = 400, imageHeight;
	color pixel_color;
	int i, j;

	// Calculate the image height and ensure that it is at least 1
	imageHeight = int(imageWidth/aspectRatio);
	imageHeight = (imageHeight < 1) ? 1 : imageHeight;

	// Camera
	viewportWidth = viewportHeight * (double(imageWidth)/imageHeight);
	

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