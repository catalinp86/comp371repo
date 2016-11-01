#pragma once
#include "Camera.h"
#include "Light.h"
#include "Triangle.h"
#include "Plane.h"
#include "Sphere.h"
#include <vector>

class ObjectHolder
{
private:
	std::vector<GenericObject*>* objectList;
	bool hasCamera;
	bool hasLightSrc;
	bool goodState;
public:
	ObjectHolder();
	ObjectHolder(std::vector<GenericObject*>* givenObjectList);
	~ObjectHolder();

	std::vector<GenericObject*>* getObjectList() { return objectList; }
	bool getState() const { return goodState; }
	bool clearList();
	bool verifyState();

	void addCamera(glm::vec3 pos, double fov, double focalLen, double aspect);
	void addLight(glm::vec3 pos, glm::vec3 color);
	void addPlane(glm::vec3 pos, glm::vec3 nor, glm::vec3 amb, glm::vec3 dif, glm::vec3 spe, double shi);
	void addTriangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3,
		glm::vec3 amb, glm::vec3 dif, glm::vec3 spe,
		double shi);
	void addSphere(glm::vec3 pos, glm::vec3 amb, glm::vec3 dif, glm::vec3 spe, double shi, double radius);
};
