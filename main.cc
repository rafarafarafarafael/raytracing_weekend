#include <iostream>
#include <cstdint>

#include "vec3.h"
#include "color.h"
#include "ray.h"

color ray_color(const ray& r){
	vec3 unitDirection = unit_vector(r.direction());
	auto a = 0.5 * (unitDirection.y() + 1.0);
	return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main()
{
	// Variables
	double aspectRatio = 16.0 / 9.0;
	double focalLength = 1.0;
	double viewportHeight = 2.0, viewportWidth;
	point3 cameraCenter = point3(0, 0, 0); 
	vec3 viewportU, viewportV, pixelDeltaU, pixelDeltaV;
	vec3 viewportUpperLeft, pixel00Loc;
	int imageWidth = 400, imageHeight;
	color pixelColor;
	int i, j;

	// Calculate the image height and ensure that it is at least 1
	imageHeight = int(imageWidth/aspectRatio);
	imageHeight = (imageHeight < 1) ? 1 : imageHeight;

	// Camera
	viewportWidth = viewportHeight * (double(imageWidth)/imageHeight);

	// Calculate the vectors across the horizontal and down the vertical viewport edges
	viewportU = vec3(viewportWidth, 0, 0);
	viewportV = vec3(viewportHeight, 0, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel
	pixelDeltaU = viewportU / imageWidth;
	pixelDeltaV = viewportV / imageHeight;

	// Calculate the loction of the upper left pixel
	viewportUpperLeft = cameraCenter - vec3(0, 0, focalLength) - viewportU/2 - viewportV/2;
	pixel00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

	// Render
	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	for (j = 0; j < imageHeight; j++){
		std::clog << "\rScanlines remaining: " << (imageHeight - j) << ' ' << std::flush;
		for(i = 0; i < imageWidth; i ++){
			auto pixelCenter = pixel00Loc + (i * pixelDeltaU) + (j * pixelDeltaV);
			auto rayDirection = pixelCenter - cameraCenter;
			ray r(cameraCenter, rayDirection);

			pixelColor = ray_color(r);
			write_color(std::cout, pixelColor);
		}
	}

	std::clog << "\rDone.                                   \n";

	return 0;
}