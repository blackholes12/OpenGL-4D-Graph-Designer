#pragma once
#include"PhyFunction.h"
namespace phy {

	static void start_rigidBodies4D(std::vector<RigidBody4D*> rigidBodies4D, std::vector<RigidBody4D*> dynamites4D2, const float dt)
	{
		for (int i = 0; i < size_of_objects4d(rigidBodies4D, dynamites4D2); i++)
		{
			if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->is_static())
			{
				if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->isGravity)
				{
					find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->forceSystems4D.push_back(new ForceSystem4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->mass * glm::vec4(0, -9.8f, 0, 0), glm::vec4(0.f)));
				}
			}
			update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i), dt);
		}
	}

	static void caculate_rigidBodies4D(std::vector<RigidBody4D*> rigidBodies4D, std::vector<RigidBody4D*> dynamites4D2, std::vector<Group*> groups, vector<Wall4D*> walls4D,vector<Wall4D*> dynamites4D, std::vector<Water4D*> waters4D, std::vector<Collision*>* collisions, std::vector<Constraint*>* constraints, const float dt)
	{
		for (int i = 0; i < size_of_objects4d(rigidBodies4D, dynamites4D2); i++)
		{
			if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->is_static())
			{
				*collisions = detect_rigidbody_edge(find_rigidbody4d(rigidBodies4D, dynamites4D2, i), i, *collisions);
			}
			for (int j = i + 1; j < size_of_objects4d(rigidBodies4D, dynamites4D2); j++)
			{
				if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->is_static())
				{
					if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, j)->is_static())
					{
						*collisions = detect_rigidbody_or_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i), find_rigidbody4d(rigidBodies4D, dynamites4D2, j), i, j, *collisions);
					}
					if (find_rigidbody4d(rigidBodies4D, dynamites4D2, j)->is_static())
					{
						*collisions = detect_rigidbody_or_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i), find_rigidbody4d(rigidBodies4D, dynamites4D2, j), i, -1, *collisions);
					}
				}
				    
				if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->is_static())
				{
					if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, j)->is_static())
					{
						*collisions = detect_rigidbody_or_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, j), find_rigidbody4d(rigidBodies4D, dynamites4D2, i), j, -1, *collisions);
					}
				}
			}
			if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->is_static())
			{
				int wallIndex0 = 0;
				for (int j = 0; j < groups.size(); j++) {
					for (int k = 0; k < groups[j]->walls4D.size(); k++) {
						if(groups[j]->isRender)
						*collisions = detect_rigidbody_or_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i), groups[j]->walls4D[k], i, size_of_objects4d(rigidBodies4D, dynamites4D2) + wallIndex0 + k, *collisions);
					}
					wallIndex0 += groups[j]->walls4D.size();
					for (Terrain4D* k : groups[j]->terrains4D) {
						*collisions = detect_rigidbody_terrain(find_rigidbody4d(rigidBodies4D, dynamites4D2, i), k, i, *collisions);
					}
				}
				for (int j = 0; j < walls4D.size(); j++)
				{
					*collisions = detect_rigidbody_or_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i), walls4D[j], i, size_of_objects4d(rigidBodies4D, dynamites4D2,groups) + j, *collisions);
				}
				for (int j = 0; j < dynamites4D.size(); j++)
				{
					*collisions = detect_rigidbody_or_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i), dynamites4D[j], i, size_of_objects4d(rigidBodies4D, dynamites4D2,groups,walls4D) + j, *collisions);
				}
			}
		}

		for (int i = 0; i < size_of_objects4d(rigidBodies4D, dynamites4D2); i++)
		{
			float count = 0.f;
			float massAdjustmentCount = 0.f;
			glm::vec4 normal4DAdd=glm::vec4(0.f);
			for (Collision* collision : *collisions)
			{
				if (collision->index1 == i)
				{
					normal4DAdd += collision->collisionManifold.normal;
					count += 1.f;
					massAdjustmentCount += 1.f / collision->massAdjustmentA;
				}
				if (collision->index2 == i)
				{
					normal4DAdd += collision->collisionManifold.normal;
					count += 1.f;
					massAdjustmentCount += 1.f / collision->massAdjustmentB;
				}
			}
			float n = 0.f;
			for (Collision* collision : *collisions)
			{
				if (collision->index1 == i || collision->index2 == i)
				{
					n += abs(dot(collision->collisionManifold.normal, normal4DAdd));
				}
			}
			for (Collision* collision : *collisions)
			{
				if (collision->index1 == i)
				{
					{
						collision->massAdjustmentA *= max(massAdjustmentCount * n / count / count, 1.f);
					}
				}
				if (collision->index2 == i)
				{
					{
						collision->massAdjustmentB *= max(massAdjustmentCount * n / count / count, 1.f);
					}
				}
			}
		}

		for (Collision* collision : *collisions)
		{
			if (collision->index2 == -1)
			{
				get_constraint(collision->index1, find_rigidbody4d(rigidBodies4D, dynamites4D2, collision->index1), collision, constraints);
			}
			if (collision->index2 != -1)
			{
				if (collision->index2 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					get_constraint(collision->index1, collision->index2, find_rigidbody4d(rigidBodies4D, dynamites4D2, collision->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, collision->index2), collision, constraints);
				}
				if (collision->index2 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					get_constraint(collision->index1, collision->index2,find_rigidbody4d(rigidBodies4D, dynamites4D2, collision->index1), find_wall4d(groups, walls4D, dynamites4D, collision->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)), collision, constraints);
				}
			}
		}

		for (unsigned i = 0; i < 20; i++)
		{
			for (Constraint* constraint : *constraints)
			{
				if (constraint->index2 == -1)
				{
					solve_rigidbody_edge(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index1), constraint, dt);
					update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index1),dt);
				}
				if (constraint->index2 != -1)
				{
					if (constraint->index2 < size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index2)->is_static())
						{
							solve_rigidbody_rigidbody(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index2), constraint, dt);
							update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index1), dt);
							update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index2), dt);
						}
						else
						{
							solve_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index2), constraint, dt);
							update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index1), dt);
							update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index2), dt);
						}
					}
					if (constraint->index2 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						solve_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index1), find_wall4d(groups, walls4D, dynamites4D, constraint->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)), constraint, dt);
						update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, constraint->index1), dt);
					}
				}
			}
		}
		constraints->clear();
		glm::vec4 dir_a_to_b;
		float dis;
		glm::vec4 dir_a_to_b_e;
		glm::vec4 force4D;
		for (size_t i = 1; i < size_of_objects4d(rigidBodies4D, dynamites4D2); i++)
		{
			RigidBody4D* a = find_rigidbody4d(rigidBodies4D, dynamites4D2, i);
			if (a->objectName == "Celestial4D")
			{
				for (size_t j = i + 1; j < size_of_objects4d(rigidBodies4D, dynamites4D2); j++)
				{
					RigidBody4D* b = find_rigidbody4d(rigidBodies4D, dynamites4D2, j);
					if (b->objectName == "Celestial4D")
					{
						dir_a_to_b = b->position4D - a->position4D;
						dis = length(dir_a_to_b);
						dir_a_to_b_e = normalize(dir_a_to_b);
						if (dis >= 0.5f)
						{
							force4D = 10.f * a->mass * b->mass * dir_a_to_b_e / pow(dis, 2.f);
						}
						else
						{
							force4D = 40.f * a->mass * b->mass * dir_a_to_b_e;
						}
						a->forceSystems4D.push_back(new ForceSystem4D(force4D, glm::vec4(0.f)));
						b->forceSystems4D.push_back(new ForceSystem4D(-force4D, glm::vec4(0.f)));
						update_rigidbody_velocity4D(b, dt);
					}
				}
				update_rigidbody_velocity4D(a, dt);
			}
		}
	}

	static void update_joints4D(std::vector<RigidBody4D*> rigidBodies4D,
		std::vector<RigidBody4D*> dynamites4D2,
		std::vector<Group*> groups,
		vector<Wall4D*> walls4D,
		vector<Wall4D*> dynamites4D,
		std::vector < Stick4D*> sticks4D,
		std::vector < Spring4D*> springs4D,
		std::vector<HingeConstraint4D*> hingeConstraints,
		std::vector<Constraint*>* constraints,
		const float dt)
	{
		for (Stick4D* i : sticks4D)
		{
			//if (i->index2 == -1)
			//{
			//	if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
			//	{
			//		i->update_rigidbody(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
			//		update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
			//	}
			//}
			if (i->index2 != -1)
			{
				if (i->index2 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && !find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_rigidbody(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_rigidbody(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
						}
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && !find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
						}
						update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
					}
					if (i->index1 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), find_wall4d(groups, walls4D,dynamites4D, i->index1- size_of_objects4d(rigidBodies4D, dynamites4D2)), dt);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), find_wall4d(groups, walls4D,dynamites4D, i->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)), dt);
						}
					}
					update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
				}
				if (i->index2 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_wall4d(groups, walls4D,dynamites4D, i->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)), dt);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_wall4d(groups, walls4D,dynamites4D, i->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)), dt);
						}
						update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
					}
				}
			}
		}
		for (Spring4D* i : springs4D)
		{
			//if (i->index2 == -1)
			//{
			//	if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
			//	{
			//		i->update_rigidbody(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
			//		update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
			//	}
			//}
			if (i->index2 != -1)
			{
				if (i->index2 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && !find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_rigidbody(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_rigidbody(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
						}
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && !find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
						}
						update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
					}
					if (i->index1 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), find_wall4d(groups, walls4D,dynamites4D, i->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)), dt);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), find_wall4d(groups, walls4D,dynamites4D, i->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)), dt);
						}
					}
					update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
				}
				if (i->index2 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_wall4d(groups, walls4D,dynamites4D, i->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)), dt);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static())
						{
							i->update_rigidbody_wall(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_wall4d(groups, walls4D,dynamites4D, i->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)), dt);
						}
						update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
					}
				}
			}
		}
		for (HingeConstraint4D* i : hingeConstraints)
		{
			if (i->index2 == -1)
			{
				if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					get_constraint(i->index1, find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), i,constraints);
				}
			}
			if (i->index2 != -1)
			{
				if (i->index2 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && !find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							get_constraint(i->index1, i->index2, find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), i, constraints);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							get_constraint(i->index1, i->index2, find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), i, constraints);
						}
						if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							get_constraint(i->index1, i->index2, find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), i, constraints,false);
						}
						if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && !find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
						{
							get_constraint(i->index2, i->index1, find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), i, constraints, true);
						}
					}
				}
			}
		}
		for (unsigned i = 0; i < 20; i++)
		{
			for (Constraint* i : *constraints)
			{
				if (i->index2 == -1)
				{
					if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						solve_rigidbody2(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), i, dt);
						update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
					}
				}
				if (i->index2 != -1)
				{
					if (i->index2 < size_of_objects4d(rigidBodies4D, dynamites4D2))
					{
						if (i->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
						{
							if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && !find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
							{
								solve_rigidbody_rigidbody2(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), i, dt);
								update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
								update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
							}
							if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
							{
								solve_rigidbody_rigidbody2(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), i, dt);
								update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
								update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
							}
							if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
							{
								solve_rigidbody_wall2(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), i, dt);
								update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), dt);
							}
							if (find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1)->is_static() && !find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2)->is_static())
							{
								solve_rigidbody_wall2(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index1), i, dt);
								update_rigidbody_velocity4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i->index2), dt);
							}
						}
					}
				}
			}
		}
		constraints->clear();
	}

	static void update_rigidBodies_position4D(std::vector<RigidBody4D*> rigidBodies4D, std::vector<RigidBody4D*> dynamites4D2, std::vector<Group*> groups, vector<Wall4D*> walls4D, vector<Wall4D*> dynamites4D, std::vector<Collision*>* collisions, const float dt)
	{
		for (int i = 0; i < size_of_objects4d(rigidBodies4D, dynamites4D2); i++)
		{
			if (!find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->is_static())
			{
				find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->set_position4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->position4D + find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->velocity4D * dt);
				find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->set_rotation4D(update(find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->rotation4D, find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->angularVelocity4D * dt));	
			}
		}
	}

	static void update_stick4D(std::vector<RigidBody4D*> rigidBodies4D,
		std::vector<RigidBody4D*> dynamites4D2,
		std::vector<Group*> groups,
		vector<Wall4D*> walls4D,
		vector<Wall4D*> dynamites4D,
		Stick4D* stick4D)
	{

		if (stick4D->index2 == -1)
		{
			if (stick4D->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
			{
				stick4D->update_stick4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, stick4D->index1));
			}
			if (stick4D->index1 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
			{
				stick4D->update_stick4D(find_wall4d(groups, walls4D,dynamites4D, stick4D->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)));
			}
		}
		if (stick4D->index2 != -1)
		{
			if (stick4D->index2 < size_of_objects4d(rigidBodies4D, dynamites4D2))
			{
				if (stick4D->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					stick4D->update_stick4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, stick4D->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, stick4D->index2));
				}
				if (stick4D->index1 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					stick4D->update_stick4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, stick4D->index2), find_wall4d(groups, walls4D,dynamites4D, stick4D->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)));
				}
			}
			if (stick4D->index2 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
			{
				if (stick4D->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					stick4D->update_stick4D(find_wall4d(groups, walls4D,dynamites4D, stick4D->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)), find_rigidbody4d(rigidBodies4D, dynamites4D2, stick4D->index1));
				}
				if (stick4D->index1 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					stick4D->update_stick4D(find_wall4d(groups, walls4D,dynamites4D, stick4D->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)), find_wall4d(groups, walls4D,dynamites4D, stick4D->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)));
				}
			}
		}
	}
	static void update_spring4D(std::vector<RigidBody4D*> rigidBodies4D,
		std::vector<RigidBody4D*> dynamites4D2,
		std::vector<Group*> groups,
		vector<Wall4D*> walls4D,
		vector<Wall4D*> dynamites4D,
		Spring4D* spring4D)
	{

		if (spring4D->index2 == -1)
		{
			if (spring4D->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
			{
				spring4D->update_spring4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, spring4D->index1));
			}
			if (spring4D->index1 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
			{
				spring4D->update_spring4D(find_wall4d(groups, walls4D,dynamites4D, spring4D->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)));
			}
		}
		if (spring4D->index2 != -1)
		{
			if (spring4D->index2 < size_of_objects4d(rigidBodies4D, dynamites4D2))
			{
				if (spring4D->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					spring4D->update_spring4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, spring4D->index1), find_rigidbody4d(rigidBodies4D, dynamites4D2, spring4D->index2));
				}
				if (spring4D->index1 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					spring4D->update_spring4D(find_rigidbody4d(rigidBodies4D, dynamites4D2, spring4D->index2), find_wall4d(groups, walls4D, dynamites4D, spring4D->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)));
				}
			}
			if (spring4D->index2 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
			{
				if (spring4D->index1 < size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					spring4D->update_spring4D(find_wall4d(groups, walls4D, dynamites4D, spring4D->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)), find_rigidbody4d(rigidBodies4D, dynamites4D2, spring4D->index1));
				}
				if (spring4D->index1 >= size_of_objects4d(rigidBodies4D, dynamites4D2))
				{
					spring4D->update_spring4D(find_wall4d(groups, walls4D, dynamites4D, spring4D->index1 - size_of_objects4d(rigidBodies4D, dynamites4D2)), find_wall4d(groups, walls4D, dynamites4D, spring4D->index2 - size_of_objects4d(rigidBodies4D, dynamites4D2)));
				}
			}
		}
	}

	static void update_trails4D(std::vector<RigidBody4D*> rigidBodies4D, std::vector<RigidBody4D*> dynamites4D2, const float dt, float curTime)
	{
		//time += 100.f*dt;
		for (int i = 0; i < size_of_objects4d(rigidBodies4D, dynamites4D2); i++)
		{
			find_rigidbody4d(rigidBodies4D, dynamites4D2, i)->update_trail4D(dt, curTime);
		}
	}

	static void clear_forces4D(std::vector<RigidBody4D*> rigidBodies4D, std::vector<RigidBody4D*> dynamites4D2)
	{
		for (RigidBody4D* i : rigidBodies4D)
		{
			i->forceSystems4D.clear();
		}
		for (RigidBody4D* i : dynamites4D2)
		{
			i->forceSystems4D.clear();
		}
	}

	static void update_physic4D(std::vector<RigidBody4D*> rigidBodies4D,
		std::vector<RigidBody4D*> dynamites4D2,
		std::vector<Group*> groups,
		vector<Wall4D*> walls4D,
		vector<Wall4D*> dynamites4D,
		std::vector<Water4D*> waters4D,
		std::vector<Collision*>* collisions,
		std::vector < Stick4D*> sticks4D,
		std::vector < Spring4D*> springs4D,
		std::vector<HingeConstraint4D*> hingeConstraints,
		std::vector<Constraint*>* constraints,
		const float dt)
	{
		unsigned steps = 1;
		for (int i = steps - 1; i >= 0; i--)
		{
			float dt2 = (2.f * ((0.5f + (float)i) / (float)steps) / (float)steps) * dt;
			start_rigidBodies4D(rigidBodies4D, dynamites4D2, dt2);
			caculate_rigidBodies4D(rigidBodies4D, dynamites4D2, groups, walls4D, dynamites4D, waters4D, collisions, constraints, dt2);
			update_joints4D(rigidBodies4D, dynamites4D2, groups, walls4D, dynamites4D, sticks4D, springs4D, hingeConstraints, constraints, dt2);
			update_rigidBodies_position4D(rigidBodies4D, dynamites4D2, groups, walls4D, dynamites4D, collisions, dt2);
			clear_forces4D(rigidBodies4D, dynamites4D2);
			if (i != 0)
			{
				collisions->clear();
			}
		}
	}

	static void before_render_physic4D(std::vector<RigidBody4D*> rigidBodies4D,
		std::vector<RigidBody4D*> dynamites4D2,
		std::vector<Group*> groups,
		vector<Wall4D*> walls4D,
		vector<Wall4D*> dynamites4D,
		std::vector < Stick4D*> sticks4D,
		std::vector < Spring4D*> springs4D,
		const float dt, float curTime)
	{
		for (Stick4D* i : sticks4D) { if (i->index2 != -1)update_stick4D(rigidBodies4D, dynamites4D2, groups, walls4D,dynamites4D, i); }
		for (Spring4D* i : springs4D) { if (i->index2 != -1)update_spring4D(rigidBodies4D, dynamites4D2, groups, walls4D,dynamites4D, i); }
		update_trails4D(rigidBodies4D, dynamites4D2, dt, curTime);
	}
}