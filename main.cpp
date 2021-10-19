#include <iostream>
#include <memory>
#include <fstream>

#include <time.h>

#include "utils.h"
#include "artist.h"

#include "surface.h"
#include "hittable.h"
#include "hittable_list.h"
#include "vec3.h"
#include "ray.h"
#include "triangle.h"
#include "camera.h"
#include "sphere.h"

using namespace std;


int main(int argc, char *argv[])
{

	std::ofstream myfile;
	myfile.open("output2.ppm");

	double x, y, z;
	double resolutionX = 1900, resolutionY = 1200;
	double colorRange = 255;



	camera cam(vec3(0, 0, 2), vec3(0, 0, 5), vec3(0, -1, 0), 100, resolutionX / resolutionY);

	
	hittable_list world;
	world.add(make_shared<sphere>(vec3(0, 0, 12), 4, vec3::GREEN, PERFECT_MIRROR));
	world.add(make_shared<sphere>(vec3(0.5, 3, 7), 1, vec3::ROSE, DIFFUSER));
	world.add(make_shared<sphere>(vec3(-12, -4, 16), 8, vec3::AZURE, DIFFUSER));
	world.add(make_shared<sphere>(vec3(4, 0.5, 5.7), 2.2, vec3::GOLD, SPECULAR));
	world.add(make_shared<triangle>(vec3(0, 4, -100), vec3(-1000, 4, 500), vec3(1000, 4, 500), vec3(50.0/255, 240.0/255, 250.0/255), DIFFUSER, 0.2));
	// world.add(make_shared<triangle>(vec3(0, -12, 1000), vec3(-50, -12, -2), vec3(50, -12, -2), vec3(50.0/255, 240.0/255, 250.0/255)));
	// world.add(make_shared<triangle>(vec3(0, -16, 500), vec3(-50, -16, -100), vec3(50, -16, -100), vec3(250.0/255, 240.0/255, 50.0/255), DIFFUSER));

	// world.add(make_shared<triangle>(vec3(-8, 0, 16), vec3(12, 4, 8), vec3(0, 20, 8), vec3::VIOLET));
	
	myfile << "P3\n"
		   << resolutionX << "\n"
		   << resolutionY << "\n" 
		   << colorRange << std::endl;
	

	// int bounce = 128;
	// int sample_rate = 2048;

	int bounce = 12;
	int sample_rate = 12;

	double pixelWidth = 1/resolutionX;
	double pixelHeight = 1/resolutionY;

	artist graphicRender = artist(vec3(vec3::BLACK));

	
	cout << endl;

	

	for (double pixelY = 0; pixelY < 1; pixelY += pixelHeight)
	{
		printf("\r Progress %.2f percent", (pixelY*100.0));

		for (double pixelX = 0; pixelX < 1; pixelX += pixelWidth)
		{
			ray* array = cam.getRays(pixelX, pixelY, pixelWidth, pixelHeight, sample_rate);


			myfile << (graphicRender.getPixelColor(array, sample_rate, world, 0.0, double_infinity, bounce) * colorRange).toString() << endl;
			
			free(array);

		
		
		}
	}
	
	printf("\r Progress 100 percent    ");

	myfile.close();
}
