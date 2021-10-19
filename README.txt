Duong Hoang Vu
760433691



enum surfaceType (in surface.h file):
	PERFECT_MIRROR: reflect perflectly
	SPECULAR: reflect by with slight randomness, create fuzzy reflection
	DIFFUSER: doesn't reflect that well


Adding sphere in main:
	world.add(make_shared<sphere>(centerPos, radius, colorVector, surfaceType));

Adding triangle in main:
	world.add(make_shared<triangle>(pointAPos, pointBPos, pointCPos, colorVector, surfaceType));



Surface type:
changing material surfaceType can be done in the constructor or using setType() function



Recursive depth and sample_rate:
In the main method, there are two int variables bounce and sample_rate
	bounce = maximum recursive depth
	sample_rate = sampling rate per pixel




Camera position:
	Can be change in the constructor.
	First parameter is the position of the camera.
	Second parameter is the point that the camera is looking at
	Third paramater is the up vector from the camera pos (this should be perpendicular to the vec3 = second param - first param)
	Fourth paramater is the FOV
	Fifth parameter is the aspect ratio