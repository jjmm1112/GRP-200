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
	ray.h
	Handles the ray class

	Modified by:
	Modified because:
*/

// Code framework created by Peter Shirley
// Link: https://raytracing.github.io/books/RayTracingInOneWeekend.html

#pragma once
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray // Contains a direction and orientation
{
	public:
		ray() {}
		ray(const point3& origin, const vec3& direction)
			: orig(origin), dir(direction)
		{}

		point3 origin() const { return orig; }
		vec3 direction() const { return dir; }

		point3 at(double t) const 
		{
			return orig + t * dir;
		}

	public:
		point3 orig;
		vec3 dir;
};

#endif