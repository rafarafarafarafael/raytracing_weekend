#include <iostream>
#include <cstdint>

int main()
{
    // Image
    const int imageWidth = 256;
    const int imageHeight = 256;
    double r, g, b;
    int i, j, ir, ig, ib;

    // Render

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\nd55\n";

    for (j = 0; j < imageHeight; j++){
        for(i = 0; i < imageWidth; i ++){
            r = double(i) / (imageWidth - 1);
            g = double(j) / (imageHeight - 1);
            b = 0.0;

            ir = int(255.999 * r);
            ig = int(255.999 * g);
            ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
        }
    }
}