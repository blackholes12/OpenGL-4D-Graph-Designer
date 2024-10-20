#pragma once
//#include <conio.h>
//#include<io.h>
//#include<iostream>
//#include<string>
//#include<fstream>
//#include<sstream>

//static unsigned texture3d_list(Texture3D* texture3D, vector<Texture3D*> textures3D)
//{
//	for (size_t i = 0; i < textures3D.size(); i++)
//	{
//		if (textures3D[i] == texture3D)
//		{
//			return i;
//		}
//	}
//}
//
//static unsigned shader_list(Shader* shader, vector<Shader*> shaders)
//{
//	for (size_t i = 0; i < shaders.size(); i++)
//	{
//		if (shaders[i] == shader)
//		{
//			return i;
//		}
//	}
//}

static unsigned name_index(const char* name)
{
	if (name == "4D-Object") return 0;
	else if (name == "Can-Be-Destroyed") return 1;
	else if (name == "Glass4D") return 2;
	else if (name == "Ground") return 3;
	else if (name == "Celestial4D") return 4;
	else if (name == "Billiard") return 5;
	else if (name == "Player") return 6;
	else if (name == "Portal") return 7;
	else return 0;
}

static const char* name_list(unsigned nameIndex)
{
	switch (nameIndex)
	{
	case 0: { return "4D-Object"; break; }
	case 1: { return "Can-Be-Destroyed"; break; }
	case 2: { return "Glass4D"; break; }
	case 3: { return "Ground"; break; }
	case 4: { return "Celestial4D"; break; }
	case 5: { return "Billiard"; break; }
	case 6: { return "Player"; break; }
	case 7: { return "Portal"; break; }
	}
}

static void save_file(const char* filePath, vector<RigidBody4D*> rigidBodies4D, vector<RigidBody4D*> dynamites4D2, std::vector<Group*> groups, vector<Wall4D*> walls4D, vector<Wall4D*> dynamites4D, vector < Water4D*> waters4D,
	vector < Stick4D*> sticks4D, vector < Spring4D*> springs4D, vector < Shift4D*> shifts4D, vector < Float4D*> floats4D, vector < Rotate4D*> rotates4D, vector < vector < HingeConstraint4D>> hingeConstraintsVec,
	vector < PointLight4D*> pointLights4D,const float worldTime)
{
	freopen(filePath, "w", stdout);
	unsigned type;
	for (size_t i(0); i < size_of_objects4d(rigidBodies4D, dynamites4D2); i++)
	{
		RigidBody4D* r(find_rigidbody4d(rigidBodies4D, dynamites4D2, i));
		if (i < rigidBodies4D.size())type = 0;
		else type = 1;
		std::cout <<type<< " " << name_index(r->objectName) <<" " << primitive_index(r->primitive4D.primitiveName) <<" " <<
			r->primitive4D.scale4D.x << " " << r->primitive4D.scale4D.y << " " << r->primitive4D.scale4D.z << " " << r->primitive4D.scale4D.w << " " <<
			r->position4D.x<<" "<< r->position4D.y << " " << r->position4D.z << " " << r->position4D.w << " " <<
			r->rotation4D.s << " "<<r->rotation4D.b.xy<<" "<< r->rotation4D.b.xz << " " << r->rotation4D.b.xw << " "
			<< r->rotation4D.b.yz << " " << r->rotation4D.b.yw << " " << r->rotation4D.b.zw << " " << r->rotation4D.q.xyzw<<" "<<
			r->scale4D.x << " " << r->scale4D.y << " " << r->scale4D.z << " " << r->scale4D.w << " " <<
			r->mass<<" " << r->momentInertiaScalar<<" " << r->mu << " "<<r->restitution << " "<<
			r->isGravity<<" "<< r->isFrozen<<" " <<
			r->velocity4D.x << " " << r->velocity4D.y << " " << r->velocity4D.z << " " << r->velocity4D.w << " " <<
			r->angularVelocity4D.xy << " " << r->angularVelocity4D.xz << " " << r->angularVelocity4D.xw << " "
			<< r->angularVelocity4D.yz << " " << r->angularVelocity4D.yw << " " << r->angularVelocity4D.zw << " " <<
			r->isSpecular<<" "<< r->texture3DIndex <<" " << 
			r->paintingColor.x << " " << r->paintingColor.y << " " << r->paintingColor.z << " " << r->paintingColor.w << " " <<
			r->metalColor.x << " " << r->metalColor.y << " " << r->metalColor.z << " " << r->metalColor.w << " " <<
			r->colType<<" "<< r->shaderIndex<<" "<<
			r->animatePosition4D.x << " " << r->animatePosition4D.y << " " << r->animatePosition4D.z << " " << r->animatePosition4D.w <<"\n";
	}
	for (size_t i(0); i < size_of_objects4d(groups, walls4D, dynamites4D); i++)
	{
		Wall4D* w(find_wall4d(groups, walls4D, dynamites4D,i));
		if(i< size_of_objects4d(groups, walls4D))type = 2;
		else type = 3;
		std::cout << type << " " << name_index(w->objectName) << " " << primitive_index(w->primitive4D.primitiveName) << " " <<
			w->primitive4D.scale4D.x << " " << w->primitive4D.scale4D.y << " " << w->primitive4D.scale4D.z << " " << w->primitive4D.scale4D.w << " " <<
			w->position4D.x << " " << w->position4D.y << " " << w->position4D.z << " " << w->position4D.w << " " <<
			w->rotation4D.s << " " << w->rotation4D.b.xy << " " << w->rotation4D.b.xz << " " << w->rotation4D.b.xw << " "
			<< w->rotation4D.b.yz << " " << w->rotation4D.b.yw << " " << w->rotation4D.b.zw << " " << w->rotation4D.q.xyzw << " " <<
			w->scale4D.x << " " << w->scale4D.y << " " << w->scale4D.z << " " << w->scale4D.w << " " <<
			w->mu << " " << w->restitution <<" "<<
			w->isSpecular << " " << w->texture3DIndex << " " << 
			w->paintingColor.x << " " << w->paintingColor.y << " " << w->paintingColor.z << " " << w->paintingColor.w << " " <<
			w->metalColor.x << " " << w->metalColor.y << " " << w->metalColor.z << " " << w->metalColor.w << " " <<
			w->colType << " "  << w->shaderIndex <<"\n";
	}
	for (size_t i(0); i < groups.size(); i++)
	{
		for (size_t j(0); j < groups[i]->terrains4D.size(); j++)
		{
			Terrain4D* t(groups[i]->terrains4D[j]);
			type = 4;
			std::cout << type <<" "<< name_index(t->objectName)<<" "<<
				t->position4D.x << " " << t->position4D.y << " " << t->position4D.z << " " << t->position4D.w << " " <<
				t->scale4D.x << " " << t->scale4D.y << " " << t->scale4D.z << " " << t->scale4D.w << " " <<
				t->mu <<" "<<t->restitution<<" "<< t->colType << " " << t->shaderIndex << "\n";
		}
	}
	for (size_t i(0); i < waters4D.size(); i++)
	{
		Water4D* w2(waters4D[i]);
		type = 5;
		std::cout << type << " " << name_index(w2->objectName) << " " << primitive_index(w2->primitive4D.primitiveName) << " " <<
			w2->primitive4D.scale4D.x << " " << w2->primitive4D.scale4D.y << " " << w2->primitive4D.scale4D.z << " " << w2->primitive4D.scale4D.w << " " <<
			w2->position4D.x << " " << w2->position4D.y << " " << w2->position4D.z << " " << w2->position4D.w << " " <<
			w2->scale4D.x << " " << w2->scale4D.y << " " << w2->scale4D.z << " " << w2->scale4D.w << " " <<
			w2->colType << " " << w2->shaderIndex <<"\n";
	}
	for (size_t i(0); i < sticks4D.size(); i++)
	{
		Stick4D* s(sticks4D[i]);
		type = 6;
		std::cout << type << " " <<
			s->fixPoint4D.x << " " << s->fixPoint4D.y << " " << s->fixPoint4D.z << " " << s->fixPoint4D.w << " " << 
			s->index1<<" "<< s->index2 << " "<<s->stickLength << " " << s->texture3DIndex <<" "<<
			s->paintingColor.x << " " << s->paintingColor.y << " " << s->paintingColor.z << " " << s->paintingColor.w << " " <<
		    s->shaderIndex <<"\n";
	}
	for (size_t i(0); i < springs4D.size(); i++)
	{
		Spring4D* s2(springs4D[i]);
		type = 7;
		std::cout << type << " " <<
			s2->fixPoint4D.x << " " << s2->fixPoint4D.y << " " << s2->fixPoint4D.z << " " << s2->fixPoint4D.w << " " <<
			s2->index1 << " " << s2->index2 << " " << s2->springLength << " " << s2->k << " " << s2->texture3DIndex << " " <<
			s2->paintingColor.x << " " << s2->paintingColor.y << " " << s2->paintingColor.z << " " << s2->paintingColor.w << " " <<
			s2->shaderIndex <<"\n";
	}
	for (size_t i(0); i < shifts4D.size(); i++)
	{
		Shift4D* s3(shifts4D[i]);
		type = 8;
		std::cout << type << " " << s3->size << " ";
		for (int j = 0; j < s3->size; j++)
		{
			std::cout << s3->positions4D[j].x << " " << s3->positions4D[j].y << " " << s3->positions4D[j].z << " " << s3->positions4D[j].w << " ";
		}
		for (int j = 0; j < s3->size-1; j++)
		{
			std::cout << s3->dt[j] << " ";
		}
		std::cout << s3->index <<"\n";
	}
	for (size_t i(0); i < floats4D.size(); i++)
	{
		Float4D* f(floats4D[i]);
		type = 9;
		std::cout << type << " " <<
			f->position4D.x << " " << f->position4D.y << " " << f->position4D.z << " " << f->position4D.w << " " <<
			f->distance << " " << f->speed << " " << f->direction4D << " " << f->index <<"\n";
	}
	for (size_t i(0); i < rotates4D.size(); i++)
	{
		Rotate4D* r2(rotates4D[i]);
		type = 10;
		std::cout << type << " " <<
			r2->position4D.x << " " << r2->position4D.y << " " << r2->position4D.z << " " << r2->position4D.w << " " <<
			r2->bodyPosition4D.x << " " << r2->bodyPosition4D.y << " " << r2->bodyPosition4D.z << " " << r2->bodyPosition4D.w << " " <<
			r2->rotation4D.s << " " << r2->rotation4D.b.xy << " " << r2->rotation4D.b.xz << " " << r2->rotation4D.b.xw << " "
			<< r2->rotation4D.b.yz << " " << r2->rotation4D.b.yw << " " << r2->rotation4D.b.zw << " " << r2->rotation4D.q.xyzw << " " <<
			r2->angularVelocity4D.xy << " " << r2->angularVelocity4D.xz << " " << r2->angularVelocity4D.xw << " "
			<< r2->angularVelocity4D.yz << " " << r2->angularVelocity4D.yw << " " << r2->angularVelocity4D.zw << " "<<
			r2->isPositionFixed << " " << r2->index1 << " " << r2->index2 <<"\n";
	}
	for (size_t i(0); i < hingeConstraintsVec.size(); i++)
	{
		vector<HingeConstraint4D> hs(hingeConstraintsVec[i]);
		type = 11;
		std::cout << type << " " << hs.size() << " ";
		for (size_t j(0); j < hs.size(); j++)
		{
			std::cout << hs[j].worldPosition4D.x << " " << hs[j].worldPosition4D.y << " " << hs[j].worldPosition4D.z << " " << hs[j].worldPosition4D.w << " " <<
				hs[j].bodyPosition4D1.x << " " << hs[j].bodyPosition4D1.y << " " << hs[j].bodyPosition4D1.z << " " << hs[j].bodyPosition4D1.w << " " <<
				hs[j].bodyPosition4D2.x << " " << hs[j].bodyPosition4D2.y << " " << hs[j].bodyPosition4D2.z << " " << hs[j].bodyPosition4D2.w << " " <<
				hs[j].index1 << " " << hs[j].index2 << " ";
		}
		std::cout << "\n";
	}
	for (size_t i(0); i < pointLights4D.size(); i++)
	{
		PointLight4D* p(pointLights4D[i]);
		type = 12;
		std::cout << type << " " << p->texture3DIndex <<" " <<
			p->position4D.x << " " << p->position4D.y << " " << p->position4D.z << " " << p->position4D.w << " " <<
			p->index << " " << p->intensity << " "<<
			p->color.x << " " << p->color.y << " " << p->color.z << " "
			<< p->radius<<"\n";
	}
	std::cout << 13 << " " << worldTime << "\n";
	freopen("CON", "w", stdout);
}

static void load_file(const char* filePath, vector<RigidBody4D*>* rigidBodies4D, vector<RigidBody4D*>* dynamites4D2, 
	vector<Wall4D*>* walls4D, vector<Wall4D*>* dynamites4D, vector < Terrain4D*>* terrains4D,vector < Water4D*>* waters4D,
	vector < Stick4D*>* sticks4D, vector < Spring4D*>* springs4D, vector < Shift4D*>* shifts4D, vector < Float4D*>* floats4D, vector < Rotate4D*>* rotates4D, vector < vector < HingeConstraint4D>>* hingeConstraintsVec,
	vector < PointLight4D*>* pointLights4D,float* worldTime)
{
	std::ifstream in_file(filePath);
	std::stringstream ss2;
	std::string line2("");
	unsigned prefix2;
	const char* temp_glint2("");
	//File open error check
	if (!in_file.is_open())
	{
		//std::cout << "level loading failed!" << "\n";
		//throw "ERROR::OBJLOADER::Could not open file.";
	}
	else
	{
		//Read one line at a time
		while (std::getline(in_file, line2))
		{
			//Get the prefix of the line
			ss2.clear();
			ss2.str(line2);
			ss2 >> prefix2;
			switch (prefix2)
			{
			case 0: { 
				unsigned nameIndex; unsigned primitiveIndex; glm::vec4 primitiveScale4D; glm::vec4 position4D; alg::rotor4 rotation4D; glm::vec4 scale4D; float mass; float momentInertiaScalar; glm::vec4 animatePosition4D; float mu; float restitution; bool isGravity; bool isFrozen; glm::vec4 velocity4D; alg::bivec4 angularVelocity4D; bool isSpecular; unsigned texture3DIndex; glm::vec4 paintingColor; glm::vec4 metalColor; unsigned int colType; unsigned shaderIndex;
				ss2 >> nameIndex >> primitiveIndex >> primitiveScale4D.x >> primitiveScale4D.y >> primitiveScale4D.z >> primitiveScale4D.w >>
					position4D.x >> position4D.y >> position4D.z >> position4D.w >>
					rotation4D.s >> rotation4D.b.xy >> rotation4D.b.xz >> rotation4D.b.xw >> rotation4D.b.yz >> rotation4D.b.yw >> rotation4D.b.zw >> rotation4D.q.xyzw >>
					scale4D.x >> scale4D.y >> scale4D.z >> scale4D.w >> mass >> momentInertiaScalar >> mu >> restitution >> isGravity >> isFrozen >>
					velocity4D.x >> velocity4D.y >> velocity4D.z >> velocity4D.w >>
					angularVelocity4D.xy >> angularVelocity4D.xz >> angularVelocity4D.xw >> angularVelocity4D.yz >> angularVelocity4D.yw >> angularVelocity4D.zw >>
					isSpecular >> texture3DIndex >> 
					paintingColor.x >> paintingColor.y >> paintingColor.z >> paintingColor.w >>
					metalColor.x >> metalColor.y >> metalColor.z >> metalColor.w >>
					colType >> shaderIndex >> animatePosition4D.x >> animatePosition4D.y >> animatePosition4D.z >> animatePosition4D.w;
				rigidBodies4D->push_back(new RigidBody4D(name_list(nameIndex), primitive_list(primitiveIndex, primitiveScale4D), position4D, rotation4D, scale4D, mass, momentInertiaScalar, mu, restitution, isGravity, isFrozen, velocity4D, angularVelocity4D, isSpecular, texture3DIndex, paintingColor, metalColor, colType, shaderIndex, animatePosition4D, true));
				RigidBody4D* a = (*rigidBodies4D)[rigidBodies4D->size() - 1];
				a->isSleep = !(length(a->velocity4D) > 0.1f || length(a->angularVelocity4D) > 0.8f || length(a->position4D - a->pPosition4D) > 0.05f);
				break; }
			case 1: { 
				unsigned nameIndex; unsigned primitiveIndex; glm::vec4 primitiveScale4D; glm::vec4 position4D; alg::rotor4 rotation4D; glm::vec4 scale4D; float mass; float momentInertiaScalar; glm::vec4 animatePosition4D; float mu; float restitution; bool isGravity; bool isFrozen; glm::vec4 velocity4D; alg::bivec4 angularVelocity4D; bool isSpecular; unsigned texture3DIndex; glm::vec4 paintingColor; glm::vec4 metalColor; unsigned int colType; unsigned shaderIndex;
				ss2 >> nameIndex >> primitiveIndex >> primitiveScale4D.x >> primitiveScale4D.y >> primitiveScale4D.z >> primitiveScale4D.w >>
					position4D.x >> position4D.y >> position4D.z >> position4D.w >>
					rotation4D.s >> rotation4D.b.xy >> rotation4D.b.xz >> rotation4D.b.xw >> rotation4D.b.yz >> rotation4D.b.yw >> rotation4D.b.zw >> rotation4D.q.xyzw >>
					scale4D.x >> scale4D.y >> scale4D.z >> scale4D.w >> mass >> momentInertiaScalar >> mu >> restitution >> isGravity >> isFrozen >>
					velocity4D.x >> velocity4D.y >> velocity4D.z >> velocity4D.w >>
					angularVelocity4D.xy >> angularVelocity4D.xz >> angularVelocity4D.xw >> angularVelocity4D.yz >> angularVelocity4D.yw >> angularVelocity4D.zw >>
					isSpecular >> texture3DIndex >> 
					paintingColor.x >> paintingColor.y >> paintingColor.z >> paintingColor.w >>
					metalColor.x >> metalColor.y >> metalColor.z >> metalColor.w >>
					colType >> shaderIndex >> animatePosition4D.x >> animatePosition4D.y >> animatePosition4D.z >> animatePosition4D.w;
				dynamites4D2->push_back(new RigidBody4D(name_list(nameIndex), primitive_list(primitiveIndex, primitiveScale4D), position4D, rotation4D, scale4D, mass, momentInertiaScalar, mu, restitution, isGravity, isFrozen, velocity4D, angularVelocity4D, isSpecular, texture3DIndex, paintingColor, metalColor, colType, shaderIndex, animatePosition4D, true));
				RigidBody4D* a = (*rigidBodies4D)[rigidBodies4D->size() - 1];
				a->isSleep = !(length(a->velocity4D) > 0.1f || length(a->angularVelocity4D) > 0.8f || length(a->position4D - a->pPosition4D) > 0.05f);
				break; }
			case 2: { 
				unsigned nameIndex; unsigned primitiveIndex; glm::vec4 primitiveScale4D; glm::vec4 position4D; alg::rotor4 rotation4D; glm::vec4 scale4D; float mu; float restitution; bool isSpecular; unsigned texture3DIndex; glm::vec4 paintingColor; glm::vec4 metalColor; unsigned int colType; unsigned shaderIndex;
				ss2 >> nameIndex >> primitiveIndex >> primitiveScale4D.x >> primitiveScale4D.y >> primitiveScale4D.z >> primitiveScale4D.w >>
					position4D.x >> position4D.y >> position4D.z >> position4D.w >>
					rotation4D.s >> rotation4D.b.xy >> rotation4D.b.xz >> rotation4D.b.xw >> rotation4D.b.yz >> rotation4D.b.yw >> rotation4D.b.zw >> rotation4D.q.xyzw >>
					scale4D.x >> scale4D.y >> scale4D.z >> scale4D.w >> mu >> restitution >>
					isSpecular >> texture3DIndex >> 
					paintingColor.x >> paintingColor.y >> paintingColor.z >> paintingColor.w >>
					metalColor.x >> metalColor.y >> metalColor.z >> metalColor.w >>
					colType >> shaderIndex;
				walls4D->push_back(new Wall4D(name_list(nameIndex), primitive_list(primitiveIndex, primitiveScale4D), position4D, rotation4D, scale4D, mu, restitution, isSpecular, texture3DIndex, paintingColor, metalColor, colType, shaderIndex));
				break; }
			case 3: { 
				unsigned nameIndex; unsigned primitiveIndex; glm::vec4 primitiveScale4D; glm::vec4 position4D; alg::rotor4 rotation4D; glm::vec4 scale4D; float mu; float restitution; bool isSpecular; unsigned texture3DIndex; glm::vec4 paintingColor; glm::vec4 metalColor; unsigned int colType; unsigned shaderIndex;
				ss2 >> nameIndex >> primitiveIndex >> primitiveScale4D.x >> primitiveScale4D.y >> primitiveScale4D.z >> primitiveScale4D.w >>
					position4D.x >> position4D.y >> position4D.z >> position4D.w >>
					rotation4D.s >> rotation4D.b.xy >> rotation4D.b.xz >> rotation4D.b.xw >> rotation4D.b.yz >> rotation4D.b.yw >> rotation4D.b.zw >> rotation4D.q.xyzw >>
					scale4D.x >> scale4D.y >> scale4D.z >> scale4D.w >> mu >> restitution >>
					isSpecular >> texture3DIndex >> 
					paintingColor.x >> paintingColor.y >> paintingColor.z >> paintingColor.w >>
					metalColor.x >> metalColor.y >> metalColor.z >> metalColor.w >>
					colType >> shaderIndex;
				dynamites4D->push_back(new Wall4D(name_list(nameIndex), primitive_list(primitiveIndex, primitiveScale4D), position4D, rotation4D, scale4D, mu, restitution, isSpecular, texture3DIndex, metalColor, paintingColor, colType, shaderIndex));
				break; }
			case 4: { 
				unsigned nameIndex; glm::vec4 position4D; glm::vec4 scale4D; float mu; float restitution; unsigned int colType; unsigned shaderIndex;
				ss2 >> nameIndex >>
					position4D.x >> position4D.y >> position4D.z >> position4D.w >>
					scale4D.x >> scale4D.y >> scale4D.z >> scale4D.w >> mu >> restitution >> colType >> shaderIndex;
				terrains4D->push_back(new Terrain4D(name_list(nameIndex), Terrain4d(glm::ivec4(position4D.x, 54, position4D.z, position4D.w)), position4D, scale4D, mu, restitution, colType, shaderIndex));
				break; }
			case 5: {
				unsigned nameIndex; unsigned primitiveIndex; glm::vec4 primitiveScale4D; glm::vec4 position4D; glm::vec4 scale4D; unsigned int colType; unsigned shaderIndex;
				ss2 >> nameIndex >> primitiveIndex >> primitiveScale4D.x >> primitiveScale4D.y >> primitiveScale4D.z >> primitiveScale4D.w >>
					position4D.x >> position4D.y >> position4D.z >> position4D.w >>
					scale4D.x >> scale4D.y >> scale4D.z >> scale4D.w >> colType >> shaderIndex;
				waters4D->push_back(new Water4D(name_list(nameIndex), primitive_list(primitiveIndex, primitiveScale4D), position4D, scale4D, colType, shaderIndex));
				break; }
			case 6: { 
				glm::vec4 fixPoint4D; int index1; int index2; float stickLength; unsigned texture3DIndex; glm::vec4 paintingColor; unsigned shaderIndex;
				ss2 >> fixPoint4D.x >> fixPoint4D.y >> fixPoint4D.z >> fixPoint4D.w >> index1 >> index2 >> stickLength >> texture3DIndex >>
					paintingColor.x >> paintingColor.y >> paintingColor.z >> paintingColor.w >> shaderIndex;
				sticks4D->push_back(new Stick4D(fixPoint4D, index1, index2, stickLength, texture3DIndex, paintingColor, shaderIndex));
				break; }
			case 7: { 
				glm::vec4 fixPoint4D; int index1; int index2; float springLength; float k; unsigned texture3DIndex; glm::vec4 paintingColor; unsigned shaderIndex;
				ss2 >> fixPoint4D.x >> fixPoint4D.y >> fixPoint4D.z >> fixPoint4D.w >> index1 >> index2 >> springLength >> k >> texture3DIndex >>
					paintingColor.x >> paintingColor.y >> paintingColor.z >> paintingColor.w >> shaderIndex;
				springs4D->push_back(new Spring4D(fixPoint4D, index1, index2, springLength, k, texture3DIndex, paintingColor, shaderIndex));
				break; }
			case 8: { 
				glm::vec4* positions4D; float* dt; unsigned int size; unsigned int index;
				ss2 >> size;
				positions4D = new glm::vec4[size];
				dt = new float[size - 1];
				for (int i(0); i < size; i++)
				{
					ss2 >> positions4D[i].x >> positions4D[i].y >> positions4D[i].z >> positions4D[i].w;
				}
				for (int i(0); i < size - 1; i++)
				{
					ss2 >> dt[i];
				}
				ss2 >> index;
				shifts4D->push_back(new Shift4D(positions4D, dt, size, index)); 
				break; }
			case 9: { 
				glm::vec4 position4D; float distance; float speed; unsigned int direction4D; unsigned int index;
				ss2 >> position4D.x >> position4D.y >> position4D.z >> position4D.w >> distance >> speed >> direction4D >> index;
				floats4D->push_back(new Float4D(position4D, distance, speed, direction4D, index));
				break; }
			case 10: { 
				glm::vec4 position4D; glm::vec4 bodyPosition4D; alg::rotor4 rotation4D; alg::bivec4 angularVelocity4D; bool isPositionFixed; unsigned int index1; unsigned int index2;
				ss2 >> position4D.x >> position4D.y >> position4D.z >> position4D.w >>
					bodyPosition4D.x >> bodyPosition4D.y >> bodyPosition4D.z >> bodyPosition4D.w >>
					rotation4D.s >> rotation4D.b.xy >> rotation4D.b.xz >> rotation4D.b.xw >> rotation4D.b.yz >> rotation4D.b.yw >> rotation4D.b.zw >> rotation4D.q.xyzw >>
					angularVelocity4D.xy >> angularVelocity4D.xz >> angularVelocity4D.xw >> angularVelocity4D.yz >> angularVelocity4D.yw >> angularVelocity4D.zw >>
					isPositionFixed >> index1 >> index2;
				rotates4D->push_back(new Rotate4D(position4D, bodyPosition4D, rotation4D, angularVelocity4D, isPositionFixed, index1, index2));
				break; }
			case 11: { 
				size_t size; glm::vec4 worldPosition4D; glm::vec4 bodyPosition4D1; glm::vec4 bodyPosition4D2; int index1; int index2;
				ss2 >> size;
				vector < HingeConstraint4D> hs;
				for (size_t i(0); i < size; i++)
				{
					ss2 >> worldPosition4D.x >> worldPosition4D.y >> worldPosition4D.z >> worldPosition4D.w >>
						bodyPosition4D1.x >> bodyPosition4D1.y >> bodyPosition4D1.z >> bodyPosition4D1.w >>
						bodyPosition4D2.x >> bodyPosition4D2.y >> bodyPosition4D2.z >> bodyPosition4D2.w >>
						index1 >> index2;
					hs.push_back(HingeConstraint4D(worldPosition4D, bodyPosition4D1, bodyPosition4D2, index1, index2));
				}
				hingeConstraintsVec->push_back(hs);
				break; }
			case 12: {
				unsigned texture3DIndex; glm::vec4 position4D; int index; float intensity; glm::vec3 color; float radius;
				ss2 >> texture3DIndex >> position4D.x >> position4D.y >> position4D.z >> position4D.w >> index >> intensity >> color.x >> color.y >> color.z >>
					radius;
				pointLights4D->push_back(new PointLight4D(texture3DIndex, position4D, index, intensity, color, radius));
				break; }
			case 13: { 
				ss2 >> *worldTime;
				break; }
			}
		}
	}
}

#include <filesystem>