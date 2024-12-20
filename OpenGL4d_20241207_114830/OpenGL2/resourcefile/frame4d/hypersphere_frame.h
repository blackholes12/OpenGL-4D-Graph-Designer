#pragma once
#include<GLFW/glfw3.h>
#include<glm.hpp>
#include<vec4.hpp>
namespace hypersphere_frame {
	static glm::vec4 frameVertices4D[] =
	{
	glm::vec4(sin(glm::radians(360.f * 0.f / 16.f)),cos(glm::radians(360.f * 0.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 1.f / 16.f)),cos(glm::radians(360.f * 1.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 2.f / 16.f)),cos(glm::radians(360.f * 2.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 3.f / 16.f)),cos(glm::radians(360.f * 3.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 4.f / 16.f)),cos(glm::radians(360.f * 4.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 5.f / 16.f)),cos(glm::radians(360.f * 5.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 6.f / 16.f)),cos(glm::radians(360.f * 6.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 7.f / 16.f)),cos(glm::radians(360.f * 7.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 8.f / 16.f)),cos(glm::radians(360.f * 8.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 9.f / 16.f)),cos(glm::radians(360.f * 9.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 10.f / 16.f)),cos(glm::radians(360.f * 10.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 11.f / 16.f)),cos(glm::radians(360.f * 11.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 12.f / 16.f)),cos(glm::radians(360.f * 12.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 13.f / 16.f)),cos(glm::radians(360.f * 13.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 14.f / 16.f)),cos(glm::radians(360.f * 14.f / 16.f)),0.f,0.f)/2.f,
	glm::vec4(sin(glm::radians(360.f * 15.f / 16.f)),cos(glm::radians(360.f * 15.f / 16.f)),0.f,0.f)/2.f,

	glm::vec4(sin(glm::radians(360.f * 0.f / 16.f)),0.f,cos(glm::radians(360.f * 0.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 1.f / 16.f)),0.f,cos(glm::radians(360.f * 1.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 2.f / 16.f)),0.f,cos(glm::radians(360.f * 2.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 3.f / 16.f)),0.f,cos(glm::radians(360.f * 3.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 4.f / 16.f)),0.f,cos(glm::radians(360.f * 4.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 5.f / 16.f)),0.f,cos(glm::radians(360.f * 5.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 6.f / 16.f)),0.f,cos(glm::radians(360.f * 6.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 7.f / 16.f)),0.f,cos(glm::radians(360.f * 7.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 8.f / 16.f)),0.f,cos(glm::radians(360.f * 8.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 9.f / 16.f)),0.f,cos(glm::radians(360.f * 9.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 10.f / 16.f)),0.f,cos(glm::radians(360.f * 10.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 11.f / 16.f)),0.f,cos(glm::radians(360.f * 11.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 12.f / 16.f)),0.f,cos(glm::radians(360.f * 12.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 13.f / 16.f)),0.f,cos(glm::radians(360.f * 13.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 14.f / 16.f)),0.f,cos(glm::radians(360.f * 14.f / 16.f)),0.f) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 15.f / 16.f)),0.f,cos(glm::radians(360.f * 15.f / 16.f)),0.f) / 2.f,

	glm::vec4(sin(glm::radians(360.f * 0.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 0.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 1.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 1.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 2.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 2.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 3.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 3.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 4.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 4.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 5.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 5.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 6.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 6.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 7.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 7.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 8.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 8.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 9.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 9.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 10.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 10.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 11.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 11.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 12.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 12.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 13.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 13.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 14.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 14.f / 16.f))) / 2.f,
	glm::vec4(sin(glm::radians(360.f * 15.f / 16.f)),0.f,0.f,cos(glm::radians(360.f * 15.f / 16.f))) / 2.f,

	glm::vec4(0.f,sin(glm::radians(360.f * 0.f / 16.f)),cos(glm::radians(360.f * 0.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 1.f / 16.f)),cos(glm::radians(360.f * 1.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 2.f / 16.f)),cos(glm::radians(360.f * 2.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 3.f / 16.f)),cos(glm::radians(360.f * 3.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 4.f / 16.f)),cos(glm::radians(360.f * 4.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 5.f / 16.f)),cos(glm::radians(360.f * 5.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 6.f / 16.f)),cos(glm::radians(360.f * 6.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 7.f / 16.f)),cos(glm::radians(360.f * 7.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 8.f / 16.f)),cos(glm::radians(360.f * 8.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 9.f / 16.f)),cos(glm::radians(360.f * 9.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 10.f / 16.f)),cos(glm::radians(360.f * 10.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 11.f / 16.f)),cos(glm::radians(360.f * 11.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 12.f / 16.f)),cos(glm::radians(360.f * 12.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 13.f / 16.f)),cos(glm::radians(360.f * 13.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 14.f / 16.f)),cos(glm::radians(360.f * 14.f / 16.f)),0.f) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 15.f / 16.f)),cos(glm::radians(360.f * 15.f / 16.f)),0.f) / 2.f,

	glm::vec4(0.f,sin(glm::radians(360.f * 0.f / 16.f)),0.f,cos(glm::radians(360.f * 0.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 1.f / 16.f)),0.f,cos(glm::radians(360.f * 1.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 2.f / 16.f)),0.f,cos(glm::radians(360.f * 2.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 3.f / 16.f)),0.f,cos(glm::radians(360.f * 3.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 4.f / 16.f)),0.f,cos(glm::radians(360.f * 4.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 5.f / 16.f)),0.f,cos(glm::radians(360.f * 5.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 6.f / 16.f)),0.f,cos(glm::radians(360.f * 6.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 7.f / 16.f)),0.f,cos(glm::radians(360.f * 7.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 8.f / 16.f)),0.f,cos(glm::radians(360.f * 8.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 9.f / 16.f)),0.f,cos(glm::radians(360.f * 9.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 10.f / 16.f)),0.f,cos(glm::radians(360.f * 10.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 11.f / 16.f)),0.f,cos(glm::radians(360.f * 11.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 12.f / 16.f)),0.f,cos(glm::radians(360.f * 12.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 13.f / 16.f)),0.f,cos(glm::radians(360.f * 13.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 14.f / 16.f)),0.f,cos(glm::radians(360.f * 14.f / 16.f))) / 2.f,
	glm::vec4(0.f,sin(glm::radians(360.f * 15.f / 16.f)),0.f,cos(glm::radians(360.f * 15.f / 16.f))) / 2.f,

	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 0.f / 16.f)),cos(glm::radians(360.f * 0.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 1.f / 16.f)),cos(glm::radians(360.f * 1.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 2.f / 16.f)),cos(glm::radians(360.f * 2.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 3.f / 16.f)),cos(glm::radians(360.f * 3.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 4.f / 16.f)),cos(glm::radians(360.f * 4.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 5.f / 16.f)),cos(glm::radians(360.f * 5.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 6.f / 16.f)),cos(glm::radians(360.f * 6.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 7.f / 16.f)),cos(glm::radians(360.f * 7.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 8.f / 16.f)),cos(glm::radians(360.f * 8.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 9.f / 16.f)),cos(glm::radians(360.f * 9.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 10.f / 16.f)),cos(glm::radians(360.f * 10.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 11.f / 16.f)),cos(glm::radians(360.f * 11.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 12.f / 16.f)),cos(glm::radians(360.f * 12.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 13.f / 16.f)),cos(glm::radians(360.f * 13.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 14.f / 16.f)),cos(glm::radians(360.f * 14.f / 16.f))) / 2.f,
	glm::vec4(0.f,0.f,sin(glm::radians(360.f * 15.f / 16.f)),cos(glm::radians(360.f * 15.f / 16.f))) / 2.f,
	};
	static GLuint frameIndices4D0[] =
	{
		0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,0,
		16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,16,
		32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,44,44,45,45,46,46,47,47,32,
		48,49,49,50,50,51,51,52,52,53,53,54,54,55,55,56,56,57,57,58,58,59,59,60,60,61,61,62,62,63,63,48,
		64,65,65,66,66,67,67,68,68,69,69,70,70,71,71,72,72,73,73,74,74,75,75,76,76,77,77,78,78,79,79,64,
		80,81,81,82,82,83,83,84,84,85,85,86,86,87,87,88,88,89,89,90,90,91,91,92,92,93,93,94,94,95,95,80
	};
}
