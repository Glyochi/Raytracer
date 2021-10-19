all: test 

test: main.o vec3.o ray.o triangle.o sphere.o hittable.o hittable_list.o surface.o artist.o camera.o utils.o 
	g++ main.o vec3.o ray.o triangle.o sphere.o hittable.o hittable_list.o surface.o artist.o camera.o utils.o -o test


main.o: main.cpp vec3.h ray.h triangle.h sphere.h hittable.h hittable_list.h surface.h artist.h camera.h utils.h 
	g++ -c main.cpp

camera.o: camera.cpp camera.h
	g++ -c camera.cpp


utils.o: utils.cpp utils.h
	g++ -c utils.cpp

artist.o: artist.cpp artist.h
	g++ -c artist.cpp

surface.o: surface.cpp surface.h
	g++ -c surface.cpp

hittable.o: hittable.cpp hittable.h
	g++ -c hittable.cpp

hittable_list.o: hittable_list.cpp hittable_list.h
	g++ -c hittable_list.cpp



ray.o: ray.cpp ray.h
	g++ -c ray.cpp

vec3.o: vec3.cpp vec3.h
	g++ -c vec3.cpp

triangle.o: triangle.cpp triangle.h
	g++ -c triangle.cpp

sphere.o: sphere.cpp sphere.h
	g++ -c sphere.cpp

clean:
	del -f *o






