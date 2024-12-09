#pragma once
//#include"Object.h"

class Group
{
private:
public:
	std::vector<size_t> walls4DIndices;
	std::vector<size_t> terrains4DIndices;
	std::vector<size_t> groupAroundIndices;
	bool isRender;
	glm::vec4 position4D;
	glm::ivec4 coordinate4D;
	Group(glm::vec4 position4D)
	{
		this->position4D = position4D;
		this->coordinate4D = position4D / 64.f;
		this->isRender = false;
	}
	~Group() {
	}
};

static glm::vec4 get_block_position4D(glm::vec4 position4D) {
	return ceil(position4D / glm::vec4(64.f) - glm::vec4(0.5f)) * 64.f;
}

static void add_group_around_indices(std::vector<Group*> groups)
{
	Group* group(groups[groups.size() - 1]);
	glm::ivec4 coordinate4D1(group->coordinate4D);
	for (size_t j(1); j < groups.size() - 1; j++)
	{
		glm::ivec4 coordinate4D2(groups[j]->coordinate4D);
		if (glm::ivec3(coordinate4D2.y, coordinate4D2.z, coordinate4D2.w) == glm::ivec3(coordinate4D1.y, coordinate4D1.z, coordinate4D1.w))
		{
			if (alg::abs(coordinate4D2.x - coordinate4D1.x) == 1)
			{
				group->groupAroundIndices.push_back(j);
				groups[j]->groupAroundIndices.push_back(groups.size() - 1);
			}
		}
		else if (glm::ivec3(coordinate4D2.x, coordinate4D2.z, coordinate4D2.w) == glm::ivec3(coordinate4D1.x, coordinate4D1.z, coordinate4D1.w))
		{
			if (alg::abs(coordinate4D2.y - coordinate4D1.y) == 1)
			{
				group->groupAroundIndices.push_back(j);
				groups[j]->groupAroundIndices.push_back(groups.size() - 1);
			}
		}
		else if (glm::ivec3(coordinate4D2.x, coordinate4D2.y, coordinate4D2.w) == glm::ivec3(coordinate4D1.x, coordinate4D1.y, coordinate4D1.w))
		{
			if (alg::abs(coordinate4D2.z - coordinate4D1.z) == 1)
			{
				group->groupAroundIndices.push_back(j);
				groups[j]->groupAroundIndices.push_back(groups.size() - 1);
			}
		}
		else if (glm::ivec3(coordinate4D2.x, coordinate4D2.y, coordinate4D2.z) == glm::ivec3(coordinate4D1.x, coordinate4D1.y, coordinate4D1.z))
		{
			if (alg::abs(coordinate4D2.w - coordinate4D1.w) == 1)
			{
				group->groupAroundIndices.push_back(j);
				groups[j]->groupAroundIndices.push_back(groups.size() - 1);
			}
		}
	}
}

static void add_wall4d_to_group(std::vector<Group*>* groups, Wall4D* wall4D,size_t wallIndex)
{
	if (alg::length(wall4D->scale4D) < 64.f)//32.f
	{
		bool isOverlap(false);
		glm::vec4 groupPosition4D(get_block_position4D(wall4D->position4D));
		for (Group* j : *groups)
		{
			if (groupPosition4D == j->position4D)
			{
				j->walls4DIndices.push_back(wallIndex);
				isOverlap = true;
			}
		}
		if (groups->size() == 0 || !isOverlap)
		{
			groups->push_back(new Group(groupPosition4D));
			(*groups)[groups->size() - 1]->walls4DIndices.push_back(wallIndex);
			add_group_around_indices(*groups);
		}
	}
	else
	{
		(*groups)[0]->walls4DIndices.push_back(wallIndex);
	}
}

static void pack_group(std::vector<Group*>* groups, std::vector<Wall4D*>* walls4D, std::vector<Terrain4D*>* terrains4D, std::vector<PointLight4D*>* pointLights4D)
{
	groups->clear();
	groups->push_back(new Group(glm::vec4(1.f)));
	for (size_t i(0); i < walls4D->size(); i++)
	{
		add_wall4d_to_group(groups, (*walls4D)[i], i);
	}
	for (size_t i(0); i < terrains4D->size(); i++)
	{
		bool isOverlap(false);
		glm::vec4 terrainPosition4D((*terrains4D)[i]->position4D);
		glm::vec4 groupPosition4D(get_block_position4D(glm::vec4(terrainPosition4D.x, ((*terrains4D)[i]->topHeight+ (*terrains4D)[i]->bottomHeight)/2.f, terrainPosition4D.z, terrainPosition4D.w)));
		for (Group* j : *groups)
		{
			if (groupPosition4D == j->position4D)
			{
				j->terrains4DIndices.push_back(i);
				isOverlap = true;
			}
		}
		if (groups->size() == 0 || !isOverlap)
		{
			groups->push_back(new Group(groupPosition4D));
			(*groups)[groups->size() - 1]->terrains4DIndices.push_back(i);
			add_group_around_indices(*groups);
		}
	}
	
	//for (unsigned i = 0; i < pointLights4D->size(); i++)
	//{
	//	if ((*pointLights4D)[i]->index<0)
	//	{
	//		bool isOverlap0 = false;
	//		glm::vec4 groupPosition4D = get_block_position4D((*pointLights4D)[i]->position4D);
	//		for (Group* j : groups)
	//		{
	//			if (groupPosition4D == j->position4D)
	//			{
	//				j->pointLights4D.push_back((*pointLights4D)[i]);
	//				pointLights4D->erase(pointLights4D->begin() + i);
	//				i--;
	//				isOverlap0 = true;
	//			}
	//		}
	//		if (groups->size() == 0 || !isOverlap0)
	//		{
	//			groups->push_back(new Group(groupPosition4D));
	//			groups[groups->size() - 1]->pointLights4D.push_back((*pointLights4D)[i]);
	//			pointLights4D->erase(pointLights4D->begin() + i);
	//			i--;
	//		}
	//	}
	//}
}