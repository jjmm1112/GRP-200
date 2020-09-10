/*
   Copyright 2020 Justin Marko

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/*
	hittable.h
	Handles some definitions for how hitting behaves

	Modified by:
	Modified because:
*/

// Code framework created by Peter Shirley
// Link: https://raytracing.github.io/books/RayTracingInOneWeekend.html

#pragma once
#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record 
{
	point3 p;
	vec3 normal;
	double t = 0;
	bool front_face = false;

	inline void set_face_normal(const ray& r, const vec3& outward_normal) 
	{
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class hittable 
{
	public:
		virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif